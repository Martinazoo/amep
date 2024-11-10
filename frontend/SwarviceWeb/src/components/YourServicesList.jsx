import React, { useEffect, useState, useContext } from 'react';
import ServiceItem from './ServiceItem';
import { CommunityContext } from '../context/CommunityContext';
import Cookies from 'js-cookie';
import YourServiceItem from './YourServiceItem';  
const YourServicesList = ({ onEdit}) => {
  const [services, setServices] = useState([]);
  const { selectedCommunity } = useContext(CommunityContext);

  useEffect(() => {
    const username = Cookies.get('username');
    const dataJSON = {
      community: selectedCommunity.name,
      username: username,
      idComunity: selectedCommunity.id,
      idCommunity: selectedCommunity.id,
    };
    console.log('/apiConsultUserAcceptedServices.json');
  
    fetch('/apiConsultUserAcceptedServices.json', {
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
  }, [selectedCommunity]);

  return (
    <div>
      <div style={{ display: 'flex', flexWrap: 'wrap', width: '100%' }}>
        {services.map((service, index) => (
          <YourServiceItem key={index} service={service} onEdit = {onEdit}/>
        ))}
      </div>
    </div>
  );
};

export default YourServicesList;
