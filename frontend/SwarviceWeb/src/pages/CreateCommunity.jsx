import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import NavBar from '../components/NavBar';
import Profile from '../components/Profile';
import '../pallette.css';
import '../Pagina.css';
import Cookies from 'js-cookie'; // Importa la llibreria de cookies
import styles from './CreateCommunity.module.css'; // Importa els estils CSS
import Card from '../components/Card';

const CreateCommunity = ({ onLogout }) => {
  const [error, setError] = useState('');
  const [formData, setFormData] = useState({
    nom: '',
    descripcio: '',
    username: Cookies.get('username'),
  });
  const navigate = useNavigate();

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData({
      ...formData,
      [name]: value
    });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    const response = await fetch('/apicreateCommunity', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(formData),
    });
    const data = await response.json();
    if(data.error == "")
        navigate('/communities');
      else
        setError(data.error);
  };

  return (
    <div className="page-container">
      <NavBar type="communities"/>
      <div className="content-container">
        <Profile onLogout={onLogout} />
        <div className={styles.formContainer}>
          <h1 className={styles.title}>Crear Comunitat</h1>
          <form className={styles.communityForm} onSubmit={handleSubmit}>
            <div className={styles.formField}>
              <label>Nom</label>
              <input
                type="text"
                name="nom"
                value={formData.nom}
                onChange={handleChange}
                required
                className={styles.inputField}
              />
            </div>
            <div className={styles.formField}>
              <label>Descripció</label>
              <textarea
                name="descripcio"
                value={formData.descripcio}
                onChange={handleChange}
                required
                className={styles.textareaField}
              />
            </div>
            <button type="submit" className={styles.submitButton}>Crear</button>
            {error && <Card tittle="" body={error} type="error" />}
          </form>
        </div>
      </div>
    </div>
  );
};

export default CreateCommunity;
