import React, { useEffect, useContext, useState } from 'react';
import Cookies from 'js-cookie';
import { CommunityContext } from '../context/CommunityContext';
import PendentTaskItem from './PendentTaskItem.jsx';

const PendentTasksList = () => {
  const { selectedCommunity } = useContext(CommunityContext);
  const [services, setServices] = useState([]);
  const [reload, setReload] = useState(false); // Estat de recàrrega

  useEffect(() => {
    const username = Cookies.get('username'); // Recupera el nom d'usuari de les cookies
    const dni = Cookies.get('dni'); // Recupera el DNI de les cookies
    console.log('Selected Community:', selectedCommunity.id);
    if (selectedCommunity && username) {
      const dataJSON = {
        dni: dni,
        communityCode: selectedCommunity.id,
      };

      fetch('./apiConsultTasks.json', { // Assegura't que coincideix amb el teu endpoint
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(dataJSON),
      })
        .then((response) => {
          if (!response.ok) {
            throw new Error('Network response was not ok');
          }
          return response.json();
        })
        .then((data) => {
          setServices(data.serveis || []); // Assegura't que 'data.serveis' no és null
        })
        .catch((error) => {
          console.error('There was a problem with the fetch operation:', error);
        });
    }
  }, [selectedCommunity, reload]); // Afegim 'reload' com a dependència

  const triggerReload = () => {
    setReload(!reload);
  };

  return (
    <div>
      <div className="llistaserveis">
        {services.length === 0 ? (
          <p>No hi ha tasques realitzant-se</p>
        ) : (
          services.map((service, index) => (
            <PendentTaskItem key={index} service={service} onReload={triggerReload} />
          ))
        )}
      </div>
    </div>
  );
};

export default PendentTasksList;
