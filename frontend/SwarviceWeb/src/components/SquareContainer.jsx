import React, { useEffect, useState, useContext } from 'react';
import Square from './SquareComponent';
import { CommunityContext } from '../context/CommunityContext';
import Cookies from 'js-cookie';

const SquareContainer = ({ doneBy, onSelect, reload, setReload }) => {
  const [selectedNumber, setSelectedNumber] = useState(null);
  const [services, setServices] = useState([]);
  const { selectedCommunity } = useContext(CommunityContext);


  const handleSelect = (number, service) => {
    setSelectedNumber(number);
    onSelect({ number, service }); // Crida la funció de callback amb un objecte
  };

  useEffect(() => {
    const fetchSentence =() => {
        if (doneBy=='notme'){
            return './apiConsultServices.json'
        } else {
            return './apiConsultUserAcceptedServices.json'
        } 
    };
    const username = Cookies.get('username');
    const dataJSON = {
      community: selectedCommunity.name,
      username: username,
      idComunity: selectedCommunity.id,
    };
    console.log(fetchSentence());
    handleSelect(null, null);
    fetch(fetchSentence(), {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(dataJSON),
    })
    .then((response) => response.json())
    .then((data) => {
        setServices(data.serveis || []); // Ensure 'data.serveis' is not null
    })
    .catch((error) => {
        console.error('There was a problem with the fetch operation:', error);
    });
  }, [selectedCommunity], [reload], [setReload]);

  return (
    <div>
        <div style={{ display: 'flex', flexWrap: 'wrap', width: '100%' }}>
            {services.map((service, index) => (
                <Square
                    key={index}
                    service={service}
                    number={index + 1}
                    isSelected={selectedNumber === index + 1}
                    onSelect={(number) => handleSelect(number, service)} // Passa el número i el servei
                />
            ))}
        </div>
    </div>
  );
};

export default SquareContainer;
