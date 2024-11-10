import React, { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import Cookies from 'js-cookie';
import styles from './modifyService.module.css'; // Asegúrate de que el archivo CSS existe y está correctamente referenciado

const EditService = ({ service }) => {
  const navigate = useNavigate();
  const [formData, setFormData] = useState({
    label: '',
    description: '',
    duration: '',
    price: '',
    username: '',
    code: '',
  });

  useEffect(() => {
    const fetchData = async () => {
      const username = Cookies.get('username');
      const code = service.code;
        console.log(code);
        console.log(username);
        console.log(service);
      if (username && code) {
        // Reemplaza con tu endpoint real para obtener los datos del servicio
        const response = await fetch(`/api/getServiceData?username=${username}&code=${code}`);
        const data = await response.json();
        if (response.ok) {
          setFormData({
            label: data.label,
            description: data.description,
            duration: data.duration,
            price: data.price,
            username: username,
            code: code,
          });
        }
      }
    };
    fetchData();
  }, [service]);

  const handleChange = (e) => {
    const username = Cookies.get('username');
    const code = service.code;
    const { name, value } = e.target;
    setFormData({
      ...formData,
      [name]: value,
      username: username,
            code: code,
    });
  };

  const saveData = async (event) => {
    event.preventDefault();

    const response = await fetch('/apimodifyService.json', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(formData),
    });

    if (response.ok) {
      try {
        const data = await response.json();
        navigate('/services');
        console.log('Service updated successfully', data);
      } catch (error) {
        console.error('Error parsing JSON:', error);
      }
    } else {
      console.error('Failed to update service:', response.statusText);
    }
  };

  const cancelar = () => {
    navigate('/services');
  };

  return (
    <div className={styles.container}>
      <form className={styles.form} onSubmit={saveData}>
        <label className={styles.label}>Label</label>
        <input
          className={styles.formField}
          type="text"
          name="label"
          value={formData.label}
          onChange={handleChange}
        />

        <label className={styles.label}>Description</label>
        <textarea
          className={styles.formField}
          name="description"
          value={formData.description}
          onChange={handleChange}
        />

        <label className={styles.label}>Duration</label>
        <input
          className={styles.formField}
          type="text"
          name="duration"
          value={formData.duration}
          onChange={handleChange}
        />

        <label className={styles.label}>Price</label>
        <input
          className={styles.formField}
          type="number"
          name="price"
          value={formData.price}
          onChange={handleChange}
        />

        <div className={styles.options}>
          <button type="submit" className={styles.submitButton}>Apply Changes</button>
          <button type="button" className={styles.cancelButton} onClick={cancelar}>Cancel</button>
        </div>
      </form>
    </div>
  );
};

export default EditService;
