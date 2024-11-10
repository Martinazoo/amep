// components/ServiceItem.jsx
import React from 'react';
import './ServiceItem.css';
import Cookies from 'js-cookie';
import { useNavigate } from 'react-router-dom'; // Assume we use react-router for navigation

const ServiceItem = ({ service, onReload }) => {
  const navigate = useNavigate();

  const handleTakeService = () => {
    const username = Cookies.get('username'); // Recupera el nom d'usuari de les cookies

    const dataJSON = {
      username: username,
      serviceCode: service.code
    };

    fetch('/apiTakeService.json', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(dataJSON),
    })
    .then((response) => {
      if (!response.ok) {
        throw new Error('Error en agafar el servei');
      }
      // Si la resposta és correcta però no retorna cap contingut
      navigate('/tasques');
    })
    .catch((error) => {
      console.error('Error:', error); // Gestió d'errors
    });
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
      <div className='take-service' onClick={handleTakeService}>
        <button className='take-button'>Fer Servei</button>
      </div>
    </div>
  );
};

export default ServiceItem;
