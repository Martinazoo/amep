import React, { useEffect, useState } from 'react';
import CommunityItem from './CommunityItem';
import styles from './CommunityList.module.css';
import Card from './Card';

const CommunityList = ({ onCommunityClick }) => {
  const [communities, setCommunities] = useState([]);
  const [error, setError] = useState(null); // Estat per gestionar els errors
  const [loading, setLoading] = useState(true); // Estat per gestionar el carregament

  useEffect(() => {
    const dataJSON = {
      username: getCookie('username'),
    };

    fetch('./apiConsultCommunities.json', {
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
        return response.json();
      })
      .then((data) => {
        setCommunities(data.communities || []); // Assegura't que 'data.communities' no és null
        setError(null); // Reinicialitza l'estat d'error si la sol·licitud és correcta
      })
      .catch((error) => {
        console.error('There was a problem with the fetch operation:', error);
        setError('There was a problem with the fetch operation.');
      })
      .finally(() => {
        setLoading(false); // Assegura't que el carregament ha finalitzat
      });
  }, []);

  const getCookie = (cname) => {
    let name = cname + '=';
    let ca = document.cookie.split(';');
    for (let i = 0; i < ca.length; i++) {
      let c = ca[i];
      while (c.charAt(0) === ' ') {
        c = c.substring(1);
      }
      if (c.indexOf(name) === 0) {
        return c.substring(name.length, c.length);
      }
    }
    return '';
  };

  if (loading) {
    return <div>Loading...</div>; // Missatge de càrrega mentre s'espera la resposta
  }

  if (error) {
    return <Card tittle="Error" body={error} type="error" />; // Missatge d'error en cas de problemes amb la sol·licitud
  }

  if (communities.length === 0) {
    return <div>Encara no estàs a cap comunitat.</div>; // Missatge quan la llista de comunitats està buida
  }

  return (
    <div id="communities" className={styles.communities}>
      <div className={styles.row}>
        {communities.map((community, index) => (
          <CommunityItem key={index} community={community} delay={index * 0.15} onClick={() => onCommunityClick(community)} />
        ))}
      </div>
    </div>
  );
};

export default CommunityList;
