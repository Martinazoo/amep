import React from 'react';
import './PendentServiceItem.css';
import { FaCheck } from 'react-icons/fa';
import { FaXmark } from 'react-icons/fa6';

const PendentServiceItem = ({ service, onReload }) => {

  const handleAccept = () => {
    const dataJSON = {
      codi: service.code,
      idCommunity: service.id_community
    };

    fetch('/apiAcceptarServei.json', {
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
        // Operació fetch amb èxit, trucar a onReload per forçar una recàrrega
        onReload();
      })
      .catch((error) => {
        console.error('There was a problem with the fetch operation:', error);
      });
  };

  const handleDeny = () => {
    const dataJSON = {
      codi: service.code,
      idCommunity: service.id_community
    };

    fetch('/apiRebutjarServei.json', {
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
      // Operació fetch amb èxit, trucar a onReload per forçar una recàrrega
      onReload();
    })
    .catch((error) => {
      console.error('There was a problem with the fetch operation:', error);
    });
    

  const getCookie = (cname) => {
    let name = cname + '=';
    let ca = document.cookie.split(';');
    for (let i = 0; i < ca.length; i++) {
      let c = ca[i];
      while (c.charAt(0) === ' ') {
        c = c.substring(1);
      }
      if (c.indexOf(name) === 0) {
        return c.substring(name.length, c.length);
      }
    }
    return '';
  };
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
      <div className="accept-defuse-buttons">
        <button className="defuse-button" onClick={handleDeny}> <FaXmark /> </button>
        <button className="accept-button" onClick={handleAccept}> <FaCheck /> </button>
      </div>
    </div>
  );
};

export default PendentServiceItem;
