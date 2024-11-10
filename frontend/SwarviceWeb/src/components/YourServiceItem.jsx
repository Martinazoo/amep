import React from 'react';
import './ServiceItem.css';
import Cookies from 'js-cookie';

const YourServiceItem = ({ service, onEdit }) => {
  const handleTakeService = () => {
    onEdit(service);
  };

  return (
    <div className="modal-content">
      <p
        className={`service-label ${
          service.label === "Comprar"
            ? "service-label-variant-1"
            : service.label === "Mascotes"
            ? "service-label-variant-2"
            : service.label === "Cuinar"
            ? "service-label-variant-3"
            : service.label === "Jardineria"
            ? "service-label-variant-4"
            : service.label === "Netejar"
            ? "service-label-variant-5"
            : "service-label-variant-6"
        }`}
      >
        {service.label}
      </p>
      <h2 className="service-title">{service.description}</h2>
      <p className="service-price">Preu: <span>{service.price}</span></p>
      <br />
      <p className="service-description">Durada del servei: <span>{service.duration}</span></p>
      <br />
      <p className="service-user">Usuari: <span>{service.username}</span></p>
      
    </div>
  );
};

export default YourServiceItem;
