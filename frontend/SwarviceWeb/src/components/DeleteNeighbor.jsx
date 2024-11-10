import React from 'react';
import './DeleteNeighbor.css';
import Cookies from 'js-cookie';
import { useNavigate } from 'react-router-dom';

const DeleteNeighbor = () => {
  const navigate = useNavigate();
    const saveData = (event) => {
        event.preventDefault();
        // Implement saveData logic here
    };

    const redirectToUserDeleted = () => {
        console.log("ara esborrarem l'usuari");
        const dni = Cookies.get('dni');
        console.log(dni);
        const dataJSON = {
            dni: dni,
        }
        fetch('/apiEraseNeighbor.json', {
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
            Cookies.remove('sessionToken');
            Cookies.remove('username');
            Cookies.remove('password');
            Cookies.remove('tokens');
            Cookies.remove('dni');
            navigate('/login');
          })
          .catch((error) => {
            console.error('There was a problem with the fetch operation:', error);
          });
    };

    return (
        <div className="container-delete">
            <form method="post" onSubmit={saveData} className="delete-user-form">
                <img src="/swarvice.png" alt="Swarvice" id="swarvice" className="swarvice-image" />
                <br /> <br />
                <label className="form-title">Esborra permanent el teu usuari</label>
                <br /> <br />
                <label className="confirmation-text">Estàs completament segur?</label><br />
                <br />
                <input type="button" value="Yes" onClick={redirectToUserDeleted} className="confirm-button" /><br />
                
            </form>
        </div>
    );
};

export default DeleteNeighbor;
