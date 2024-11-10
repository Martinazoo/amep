import React, { useEffect, useContext, useState } from 'react';
import Cookies from 'js-cookie';
import { CommunityContext } from '../context/CommunityContext';
import PendentServiceItem from './PendentServiceItem';

const PendentServicesList = () => {
  const { selectedCommunity } = useContext(CommunityContext);
  const [services, setServices] = useState([]);
  const [reload, setReload] = useState(false); // Estat de recàrrega

  useEffect(() => {
    const username = Cookies.get('username'); // Recupera el nom d'usuari de les cookies

    if (selectedCommunity && username) {
      const dataJSON = {
        username: username,
        community: selectedCommunity.name,
      };

      fetch('./apiConsultPendingServices.json', { // Assegura't que coincideix amb el teu endpoint
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
          <p>No hi ha serveis pendents a revisar!</p>
        ) : (
          services.map((service, index) => (
            <PendentServiceItem key={index} service={service} onReload={triggerReload} />
          ))
        )}
      </div>
    </div>
  );
};

export default PendentServicesList;
