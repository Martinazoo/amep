import React, { useEffect, useState } from 'react';
import CollaborationItem from './CollaborationItem';
import './CollaborationList.css';

const CollaborationList = ({ community, listId }) => {
  const [services, setServices] = useState([]);
  const [selectedService, setSelectedService] = useState(null);

  const handleSelectService = (service) => {
    setSelectedService(service);

  };

  useEffect(() => {
    const dataJSON = {
      community: community.name,
    };

    const apiEndpoint = listId === 1 ? './apiConsultServices.json' : './apiConsultUserAcceptedServices.json';

    fetch(apiEndpoint, {
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
  }, [community, listId]);

  return (
    <div className="collaboration-list-container">
      {services.length === 0 ? (
        <p>No hi ha cap servei disponible ara mateix</p>
      ) : (
        services.map((service, index) => (
          <CollaborationItem
            key={index}
            service={service}
            isSelected={selectedService && selectedService.id === service.id}
            onSelect={handleSelectService}
          />
        ))
      )}
    </div>
  );
};

export default CollaborationList;
