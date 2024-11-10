import React, { useState, useContext } from 'react';
import styles from './AddNeighbor.module.css';
import { CommunityContext } from '../context/CommunityContext'; // Importa el context

const AddNeighbor = ({ onCancel, onAddSuccess }) => {
  const [username, setUsername] = useState('');
  const { selectedCommunity } = useContext(CommunityContext); // Usa el context

  const handleChange = (e) => {
    setUsername(e.target.value);
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      const response = await fetch('/apiAddNeighbor.json', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({ username, community: selectedCommunity.name }),
      });

      if (response.ok) {
        onAddSuccess(); // Crida a la funció onAddSuccess després d'afegir el veí
      } else {
        console.error('Failed to add neighbor');
      }
    } catch (error) {
      console.error('Error:', error);
    }
  };

  return (
    <div className={styles.formContainer}>
      <h1 className={styles.title}>Afegir Veí</h1>
      <form className={styles.neighborForm} onSubmit={handleSubmit}>
        <div className={styles.formField}>
          <label>Nom d'usuari</label>
          <input
            type="text"
            name="username"
            value={username}
            onChange={handleChange}
            required
            className={styles.inputField}
          />
        </div>
        <div className={styles.buttons}>
          <button type="submit" className={styles.submitButton}>Afegir</button>
          <button type="button" className={styles.cancelButton} onClick={onCancel}>Cancel·lar</button>
        </div>
      </form>
    </div>
  );
};

export default AddNeighbor;
