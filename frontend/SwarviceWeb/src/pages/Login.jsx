import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom'; // Importa useNavigate
import styles from './login.module.css'; // Importa els estils del CSS Module
import swarvice from '../assets/img/swarvice.png'; // Importa la imatge de Swarvice

const Login = ({ onLoginSuccess }) => {

  const [error, setError] = useState("no error");

  const navigate = useNavigate(); // Inicialitza useNavigate
  const [formData, setFormData] = useState({
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

  const handleSubmit = async (e) => {
    e.preventDefault();

    const response = await fetch('/api/loginvalidation.json', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(formData),
    });
    const error = "hola";
    const data = await response.json();
    if (data.validation) {
      document.cookie = `username=${formData.username};`;
      document.cookie = `password=${formData.password};`;
      document.cookie = `tokens=${data.tokens};`; // Emmagatzema el token JWT a les cookies
      document.cookie = `dni=${data.dni};`; // Emmagatzema el DNI a les cookies
      document.cookie = `name=${data.name};`; // Emmagatzema el nom a les cookies
      console.log(data.username);
      onLoginSuccess();
    } else {
      setError(data.error)
      console.log(data.error);
    }
  };

  const handleRegisterClick = () => {
    navigate('/register'); // Redirigeix a la pàgina de registre
  };



  return (

    <div className={styles.loginContainer}>
      <form id="login" className={styles.loginForm} onSubmit={handleSubmit}>
        <img src={swarvice} id="swarvice" className={styles.loginSwarviceImage} alt="Swarvice" style={{ width: '150px', height: '150px' }} />
        <br /> <br />
        <label className={styles.loginLabel} style={{ fontSize: '40px' }}>Login</label>
        <br /> <br />
        <label className={styles.loginLabel} style={{ fontSize: 'medium' }}>Usuari</label>
        <input
          type="text"
          name="username"
          placeholder="Username"
          required
          value={formData.username}
          onChange={handleChange}
          className={styles.loginInputField}
        />
        <br />
        <br />
        <label className={styles.loginLabel} style={{ fontSize: 'medium' }}>Constrasenya</label>
        <input
          type="password"
          name="password"
          placeholder="Password"
          required
          value={formData.password}
          onChange={handleChange}
          className={styles.loginInputField}
        />
        <br />
        <br />
        <input type="submit" value="Login" className={styles.loginSubmitButton} />
        { error !== "no error" ? <div className={styles.error}>{error}</div> : null }
        <div className={styles.loginRow}>
          <span style={{ padding: '12px' }}>No estàs registrat?</span>
          <button type="button" onClick={handleRegisterClick} style={{ padding: '12px', background: 'none', border: 'none', color: 'blue', textDecoration: 'underline', cursor: 'pointer' }}>
            Registra't aquí
          </button>
        </div>
      </form>
    </div>
  );
};

export default Login;
