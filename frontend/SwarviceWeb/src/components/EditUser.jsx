import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import Cookies from 'js-cookie';
import styles from './editUser.module.css'; // Ensure the CSS file exists and is correctly referenced

const EditUser = () => {
  const navigate = useNavigate();
  const [formData, setFormData] = useState({
    username: Cookies.get('username'),
    name: '',
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

    const response = await fetch('/apiModifyNeighbor', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(formData),
    });

    const data = await response.json();
    if (data.error == "") {
      Cookies.set('username', formData.username);
      navigate('/communities');
      console.log('User updated successfully');
    }
  };

  const cancelar = () => {
    navigate('/profile');
  };
  const username = Cookies.get('username');
  const name = Cookies.get('name');
  return (
        <>
            <div className={styles.container}>
                <form className={styles.form} onSubmit={saveData}>
        
                
                <label className={styles.label}>Nou nom</label>
                <input
                className={styles.formField}
                type="text"
                name="name"
                placeholder= {name}
                value={formData.name}
                onChange={handleChange}
                />
                
                <label className={styles.label}>Nova contrasenya</label>
                <input
                className={styles.formField}
                type="password"
                name="password"
                placeholder="Contrasenya"
                value={formData.password}
                onChange={handleChange}
                />
                
                <div className={styles.options}>
                <button type="submit" className={styles.submitButton}>Aplicar canvis</button>
                </div>
            </form>
            </div>
        </>
  );
};

export default EditUser;
