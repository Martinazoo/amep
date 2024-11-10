import React, { useEffect, useState } from 'react';
import ServiceItem from './ServiceItem';
import Cookies from 'js-cookie';
import './ServicesList.css';
import Card from './Card';

const ServicesList = ({ community, username, serveis }) => {
  const [services, setServices] = useState([]);
  const [reload, setReload] = useState(false); // Estat de recàrrega

  useEffect(() => {
    setServices(serveis);
  }, [serveis]);

  console.log('serveis:', serveis);
  

  const triggerReload = () => {
    setReload(!reload);
  };
  return (
    <>
    {(services == null || services.length === 0) ? (
      <Card tittle="" body="No hi ha cap servei disponible ara mateix" />
    ) : (
      <div className="llistaserveis">
        {services.map((service, index) => (
            <ServiceItem key={index} service={service} />
        ))}
        </div>
      )}
    </>
  );
};

export default ServicesList;
