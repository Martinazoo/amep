import React, { useContext, useState, useEffect } from 'react';
import { FaPlus } from 'react-icons/fa';
import NavBar from '../components/NavBar';
import Profile from '../components/Profile';
import NeighborsList from '../components/NeighborsList';
import AddNeighbor from '../components/AddNeighbor'; // Importa el component AddNeighbor
import '../pallette.css';
import '../Pagina.css';
import { CommunityContext } from '../context/CommunityContext'; // Importa el context
import Cookies from 'js-cookie';

const Neighbors = ({ onLogout }) => {
  const { selectedCommunity } = useContext(CommunityContext); // Usa el context
  const [showForm, setShowForm] = useState(false); // Estat per alternar entre NeighborsList i AddNeighbor
  const [isAdmin, setIsAdmin] = useState(false); // Estat per gestionar si l'usuari és administrador

  useEffect(() => {
    const username = Cookies.get('username');
    if (username && selectedCommunity) {
      const dataJSON = {
        username: username,
        community: selectedCommunity.name,
      };

      fetch('./apiValidateAdmin.json', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(dataJSON),
      })
      .then((response) => response.json())
      .then((data) => {
        if (data.validation) {
          setIsAdmin(true);
        } else {
          setIsAdmin(false);
        }
      })
      .catch((error) => {
        console.error('Error fetching admin status:', error);
        setIsAdmin(false);
      });
    }
  }, [selectedCommunity]);

  const handlePlusIconClick = () => {
    setShowForm(true);
  };

  const handleCancel = () => {
    setShowForm(false);
  };

  const handleAddSuccess = () => {
    setShowForm(false);
  };

  return (
    <div className="page-container">
      <NavBar type="services" />
      <div className="content-container">
        <Profile onLogout={onLogout} />
        <h1 id="title_communities">{selectedCommunity?.name}</h1>
        {showForm ? (
          <AddNeighbor onCancel={handleCancel} onAddSuccess={handleAddSuccess} />
        ) : (
          <NeighborsList />
        )}
        {!showForm && isAdmin && (
          <div className="plus-icon" onClick={handlePlusIconClick}>
            <FaPlus />
          </div>
        )}
      </div>
    </div>
  );
};

export default Neighbors;
