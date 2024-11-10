import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import styles from './register.module.css'; // Assegura't que el fitxer CSS existeix i està correctament referenciat

const Register = () => {
  
  const [error, setError] = useState("no error");
  const navigate = useNavigate();
  const [formData, setFormData] = useState({
    dni: '',
    mail: '',
    name: '',
    username: '',
    password: '',
  });

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData({
      ...formData,
      [name]: value,
    });
  };

  const saveData = async (event) => {
    event.preventDefault();

    const response = await fetch('/apiregisterNeighbor.json', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(formData),
    });
    const data = await response.json();
    if (response.ok) {
      if(data.error != ""){
        setError(data.error);
      } else {
        document.cookie = `username=${formData.username};`;
        document.cookie = `password=${formData.password};`;
        navigate('/communities');
        console.log('Registre correcte');
      }
    }
  };

  const cancelar = () => {
    navigate('/login');
  };

  return (
    <div className={styles.container}>
      <form className={styles.form} onSubmit={saveData}>
        <br /><br /><br />
        <label className={styles.label} style={{ fontSize: '40px' }}>Registre</label>
        <br /><br />
        <label className={styles.label} style={{ fontSize: 'medium' }}>DNI</label>
        <input
          className={styles.formField}
          type="text"
          name="dni"
          placeholder="DNI"
          value={formData.dni}
          onChange={handleChange}
        />
        <br /><br />
        <label className={styles.label} style={{ fontSize: 'medium' }}>Correu electrònic</label>
        <input
          className={styles.formField}
          type="email"
          name="mail"
          placeholder="Correu electrònic"
          value={formData.mail}
          onChange={handleChange}
        />
        <br /><br />
        <label className={styles.label} style={{ fontSize: 'medium' }}>Nom complet</label>
        <input
          className={styles.formField}
          type="text"
          name="name"
          placeholder="Nom complet"
          value={formData.name}
          onChange={handleChange}
        />
        <br /><br />
        <label className={styles.label} style={{ fontSize: 'medium' }}>Nom d'usuari</label>
        <input
          className={styles.formField}
          type="text"
          name="username"
          placeholder="Nom d'usuari"
          value={formData.username}
          onChange={handleChange}
        />
        <br /><br />
        <label className={styles.label} style={{ fontSize: 'medium' }}>Contrasenya</label>
        <input
          className={styles.formField}
          type="password"
          name="password"
          placeholder="Contrasenya"
          value={formData.password}
          onChange={handleChange}
        />
        <br /><br />
        { error !== "no error" ? <div className={styles.error}>{error}</div> : null }
        <div className={styles.options}>
          <div className={styles.bot_cancel} onClick={cancelar}>
            <input type="button" value="Cancelar" className={styles.cancelButton} />
          </div>
          
          <div className={styles.bot_reg}>
            <input type="submit" value="Registrar" className={styles.submitButton} />
          </div>
        </div>

        <div className={styles.row}>
          <span style={{ padding: '12px' }}>Ja estàs registrat?</span>
          <button type="button" onClick={() => navigate('/login')} style={{ padding: '12px', background: 'none', border: 'none', color: 'blue', textDecoration: 'underline', cursor: 'pointer' }}>
            Inicia sessió aquí
          </button>
        </div>
      </form>
    </div>
  );
};

export default Register;
