import React, { useEffect, useState, useContext } from 'react';
import NeighborItem from './NeighborItem';
import styles from './NeighborsList.module.css';
import { CommunityContext } from '../context/CommunityContext'; // Importa el context

const NeighborsList = () => {
  const [neighbors, setNeighbors] = useState([]);
  const { selectedCommunity } = useContext(CommunityContext); // Usa el context per obtenir la comunitat seleccionada
  const [reload, setReload] = useState(false); // Estat de recàrrega
  useEffect(() => {
    const fetchNeighbors = async () => {
      if (!selectedCommunity) return;

      const response = await fetch('/apiconsultNeighbors.json', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({ community: selectedCommunity.name }),
      });

      const data = await response.json();
      setNeighbors(data.neighborsCom || []); // Assegura't d'usar el camp correcte
    };

    fetchNeighbors();
  }, [selectedCommunity, reload]);

  if (!selectedCommunity) {
    return <div>Selecciona una comunitat per veure els veïns.</div>;
  }
  const triggerReload = () => {
    setReload(!reload);
  };

  return (
    <div className={styles.neighborsList}>
      {neighbors.length > 0 ? (
        neighbors.map((neighbor, index) => (
          <NeighborItem key={index} neighbor={neighbor} onReload={triggerReload}/> // Usa `dni` com a `key`
        ))
      ) : (
        <div>No hi ha veïns a mostrar.</div>
      )}
    </div>
  );
};

export default NeighborsList;
