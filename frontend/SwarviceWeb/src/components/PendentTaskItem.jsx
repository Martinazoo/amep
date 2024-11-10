import React from 'react';
import './PendentServiceItem.css';
import Cookies from 'js-cookie';
import { useNavigate } from 'react-router-dom';
const PendentTaskItem = ({ service, onReload }) => {
    const navigate = useNavigate();

    const handleAccept = () => {
        
        const dni = Cookies.get('dni');
        const dataJSON = {
            code: service.code,
            username: dni,
            exchangeUsername: service.username,
        };
        console.log(dataJSON);
        fetch('/apiEndService.json', {
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
                // No esperar el JSON, simplement continuar
                console.log('Servei finalitzat');
                Cookies.set('tokens', parseInt(Cookies.get('tokens')) + service.price);
                navigate('/services');
            })
            .catch((error) => {
                console.error('There was a problem with the fetch operation:', error);
            });
    };

    // Resta del component

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
                <button className="accept-button" onClick={handleAccept}> Finalitzar Servei </button>
            </div>
        </div>
    );
};

export default PendentTaskItem;
