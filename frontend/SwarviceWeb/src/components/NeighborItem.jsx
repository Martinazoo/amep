import React, { useEffect, useState, useContext, useCallback } from 'react';
import styles from './NeighborItem.module.css';
import { FaTrash } from 'react-icons/fa';
import Cookies from 'js-cookie'; // Asegúrate de tener la librería js-cookie instalada
import { CommunityContext } from '../context/CommunityContext';

const NeighborItem = ({ neighbor, onReload }) => {
  const { selectedCommunity } = useContext(CommunityContext);
  
  const handleTrashClick = () => {
    const dni=Cookies.get('dni');
    const dataJSON = {
      dni: neighbor.dni,
      community: selectedCommunity.name,
    };
    console.log(dataJSON);
    fetch('/apileaveCommunity.json', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(dataJSON),
    })
      .then((response) => {
        
        
        onReload();
      })
        // Operació fetch amb èxit, trucar a onReload per forçar una recàrrega
        
      .catch((error) => {
        console.error('There was a problem with the fetch operation:', error);
      });
  };
  return (
    <div className={styles.neighborItem}>
      <h3 className={styles.neighborName}>{neighbor.name}</h3>
      <p className={styles.neighborEmail}>{neighbor.mail}</p>
      <p className={styles.neighborPhone}>{neighbor.username}</p>
      <div className='trashdiv'>
        <button className={styles.trashButton} onClick={handleTrashClick}>
          <FaTrash />
        </button>
      </div>
    </div>
  );
};

export default NeighborItem;
