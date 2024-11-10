import React, { useContext, useState } from 'react';
import NavBar from '../components/NavBar';
import Profile from '../components/Profile';
import CollaborationList from '../components/CollaborationList';
import '../pallette.css';
import '../Pagina.css';
import { CommunityContext } from '../context/CommunityContext';
import SquareContainer from '../components/SquareContainer';
import { useNavigate } from 'react-router-dom';

const Colaboracio = ({ onLogout }) => {
  const navigate = useNavigate();
  const { selectedCommunity } = useContext(CommunityContext);
  const [selectedService, setSelectedService] = useState(null);
  const [selectedYourService, setSelectedYourService] = useState(null);
  const [reload, setReload] = useState(false); // Estat de recàrrega
  const handleSelectService = (selection) => {
    setSelectedService(selection);
  };

  const handleSelectYourService = (selection) => {
    setSelectedYourService(selection);
  };

  const handleExchange = () => {
    console.log('Intercanviant serveis:');
    console.log('Selected Service:', selectedService.service.username);
    console.log('Selected Your Service:', selectedYourService);
    const dataJSON = {
      usr : selectedYourService.service.username,
      usrExchange : selectedService.service.username,
      codeServiceExchange : selectedService.service.code,
      codeServiceNeighbor : selectedYourService.service.code,
    };
    fetch('./apiExchangeService.json', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(dataJSON), // Converteix l'objecte a una cadena JSON
    })
      .then((response) => {
        if (!response.ok) {
          throw new Error('Network response was not ok');
        }
  
      })
      .then((data) => {
        console.log("S'ha fet l'intercanvi amb èxit");
        // Operació fetch amb èxit, trucar a onReload per forçar una recàrrega
        setReload(true);
        navigate('/tasques')
      })
      .catch((error) => {
        console.error('There was a problem with the fetch operation:', error);
      });
    // Implement the exchange logic here
  };

  return (
    <div className="colaboracio-page-container">
      <NavBar type="services" />
      <div className="colaboracio-content-container">
        <Profile onLogout={onLogout} />
        <h1 id="colaboracio-title_communities">{selectedCommunity?.name}</h1>
        <div className="colaboracio-services-container">
          <div className="colaboracio-services-list">
            <h2>Serveis disponibles al {selectedCommunity.name}</h2>
            <div className='container-serveis'>
              <SquareContainer doneBy="notme" onSelect={handleSelectService} reload={reload} setReload={setReload}/>
            </div>
          </div>
          <div className="colaboracio-services-list">
            <h2>Els teus serveis</h2>
            <SquareContainer doneBy="me" onSelect={handleSelectYourService} reload={reload} setReload={setReload}/>
          </div>
        </div>
        <button
          className="exchange-button"
          onClick={handleExchange}
        >
          Intercanviar
        </button>
      </div>
    </div>
  );
};

export default Colaboracio;
