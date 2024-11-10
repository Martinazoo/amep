import React, { useContext } from 'react';
import { FaTrash } from 'react-icons/fa';
import NavBar from '../components/NavBar';
import { useNavigate } from 'react-router-dom';
import Profile from '../components/Profile';
import PendentServicesList from '../components/PendentServicesList';
import '../pallette.css';
import '../Pagina.css';
import Cookies from 'js-cookie';
import { CommunityContext } from '../context/CommunityContext'; // Import the context

const Services = ({ onLogout }) => {
  const { selectedCommunity } = useContext(CommunityContext); // Use context
  const navigate = useNavigate();
  const handleDeleteCommunity = async () => {
    const username = Cookies.get('username');
    const dataJSON = {
      username: username,
      name: selectedCommunity.name,
    };
    try {
      const response = await fetch('/apiDeleteCommunity.json', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(dataJSON),
      });

      if (!response.ok) {
        throw new Error('Error en esborrar la comunitat');
      }
      navigate('/communities');
      // Redirigir a /communities després d'esborrar la comunitat
    } catch (error) {
      console.error('Hi ha hagut un problema amb el fetch:', error);
    }
  };

  return (
    <div className="page-container">
      <NavBar type="services" />
      <div className="content-container">
        <Profile onLogout={onLogout} />
        <h1 id="title_communities">{selectedCommunity?.name}</h1>
        <PendentServicesList />
        <div className="delete-icon" onClick={handleDeleteCommunity}>
    <FaTrash className="icon" />
    <span>Esborrar comunitat</span>
</div>
      </div>
    </div>
  );
};

export default Services;
