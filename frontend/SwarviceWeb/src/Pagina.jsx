import React, { useState, useEffect } from 'react';
import { FaPlus } from 'react-icons/fa'; // Assegura't de tenir react-icons instal·lat
import NavBar from './components/NavBar';
import Profile from './components/Profile';
import CommunityList from './components/CommunityList';
import ServicesList from './components/ServicesList';
import './pallette.css';
import './Pagina.css';

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

const Pagina = () => {
  const [user, setUser] = useState({
    username: getCookie('username'),
    password: getCookie('password'),
  });
  const [tokens, setTokens] = useState(0);
  const [selectedCommunity, setSelectedCommunity] = useState(null);

  useEffect(() => {
    fetch('/apiloginvalidation.json', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(user),
    })
      .then((response) => response.json())
      .then((data) => {
        if (data.validation) {
          setTokens(data.tokens);
        } else {
          window.location.href = './';
        }
      });
  }, [user]);

  const handleCommunityClick = (community) => {
    setSelectedCommunity(community);
  };

  const handlePlusIconClick = () => {
    // Aquí pots definir el comportament quan es clica la icona de +
    console.log('Icòna de + clicada');
    // Per exemple, pots canviar d'estat, navegar a una altra pantalla, etc.
  };

  const getNavigationType = () => {
    return selectedCommunity == null ? "communities" : "services";
  };

  const getTitle = () => {
    return selectedCommunity == null ? "LES TEVES COMUNITATS:" : selectedCommunity.name;
  };

  return (
    <div className="page-container">
      <NavBar type={getNavigationType()} />
      <div className="content-container">
        <Profile username={user.username} tokens={tokens} />
        <h1 id="title_communities">{getTitle()}</h1>
        {selectedCommunity == null ? (
          <CommunityList onCommunityClick={handleCommunityClick} />
        ) : (
          <ServicesList community={selectedCommunity} username={user.username} />
        )}
        {selectedCommunity && (
          <div className="plus-icon" onClick={handlePlusIconClick}>
            <FaPlus />
          </div>
        )}
      </div>
    </div>
  );
};

export default Pagina;
