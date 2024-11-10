import React, { useState, useContext, useEffect } from 'react';
import './PublishService.css';
import { CommunityContext } from '../context/CommunityContext'; // Assegura't que el camí és correcte
import { ETIQUETES } from '../constants/constants';

const ServeiForm = ({ onCancel }) => {
  const { selectedCommunity } = useContext(CommunityContext); // Accedir al context
  const [formData, setFormData] = useState({
    label: 'Cuinar',
    description: '',
    price: '',
    duration: '',
    username: '',
    idCommunity: '', // Inicialment buit
  });

  const [formValid, setFormValid] = useState(false);

  useEffect(() => {
    console.log('Selected Community:', selectedCommunity); // Afegir aquest log per veure el contingut
    setFormData(prevData => ({
      ...prevData,
      username: getCookie('username'),
      idCommunity: selectedCommunity ? selectedCommunity.id : ''
    }));
  }, [selectedCommunity]);

  useEffect(() => {
    validateForm();
  }, [formData]);

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData(prevData => ({
      ...prevData,
      [name]: value
    }));
  };

  const validateForm = () => {
    const { label, description, price, duration } = formData;
    const isValid = label && description && price && duration;
    setFormValid(isValid);
  };

  const saveData = async (event) => {
    event.preventDefault();

    if (!formValid) {
      alert("Tots els camps són obligatoris");
      return;
    }

    // Assegura't que el camp idCommunity està actualitzat just abans d'enviar les dades
    const dataToSend = {
      ...formData,
      idCommunity: selectedCommunity ? selectedCommunity.id : ''
    };

    try {
      const response = await fetch('./apiPublicarServei.json', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(dataToSend),
      });

      if (response.ok) {
        // Acció a realitzar quan la resposta és correcta
        console.log('Dades enviades correctament');
        onCancel(); // Torna a la pàgina anterior
      } else {
        // Acció a realitzar quan hi ha un error
        console.error('Error en enviar les dades');
      }
    } catch (error) {
      // Maneig d'errors de xarxa
      console.error('Error de xarxa:', error);
    }
  };

  const getCookie = (name) => {
    const value = `; ${document.cookie}`;
    const parts = value.split(`; ${name}=`);
    if (parts.length === 2) return parts.pop().split(';').shift();
    return '';
  };

  return (
    <form id="serveiForm" className="serveiForm" onSubmit={saveData}>
      <br /><br />
      <label style={{ fontSize: '40px' }}>Publicar Servei</label>
      <br /><br /><br />
      <div className="input-container">
        <label style={{ fontSize: 'medium' }}>Etiqueta</label>
        <select name="label" value={formData.label} onChange={handleChange}>
        {Object.values(ETIQUETES).map((etiqueta) => (
          <option value={etiqueta} key={etiqueta}>
            {etiqueta}
          </option>
        ))}
        </select>
      </div>
      <br />
      <div className="input-container">
        <label>Descripció</label>
        <input type="text" name="description" placeholder="Descripció" value={formData.description} onChange={handleChange} />
      </div>
      <br />
      <div className="input-container">
        <label style={{ fontSize: 'medium' }}>Preu</label>
        <input type="number" name="price" placeholder="Preu" value={formData.price} onChange={handleChange} />
      </div>
      <br />
      <div className="input-container">
        <label style={{ fontSize: 'medium' }}>Durada</label>
        <input type="time" name="duration" placeholder="Durada" value={formData.duration} onChange={handleChange} />
      </div>
      <br /><br />
      <div className="options">
        <div className="bot_cancel">
          <button type="button" onClick={onCancel} className="cancel-button">Cancelar</button>
        </div>
        <div className="bot_reg">
          <button type="submit" className="submit-button" disabled={!formValid}>Publicar</button>
        </div>
      </div>
    </form>
  );
};

export default ServeiForm;
