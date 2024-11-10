import React, { useContext } from 'react';
import { FaPlus } from 'react-icons/fa';
import NavBar from '../components/NavBar';
import Profile from '../components/Profile';
import CommunityList from '../components/CommunityList';
import { useNavigate } from 'react-router-dom';
import '../pallette.css';
import '../Pagina.css';
import { CommunityContext } from '../context/CommunityContext'; // Import the context

const Communities = ({ onLogout }) => {
  const navigate = useNavigate();
  const { setSelectedCommunity } = useContext(CommunityContext); // Use context

  const onCommunityClick = (community) => {
    setSelectedCommunity(community); // Update context
    navigate('/services');
  };

  return (
    <div className="page-container">
      <NavBar type="communities" />
      <div className="content-container">
        <Profile onLogout={onLogout} /> {/* Passa la funció handleLogout */}
        <h1 id="title_communities">LES TEVES COMUNITATS:</h1>
        <CommunityList onCommunityClick={onCommunityClick} />
      </div>
    </div>
  );
};

export default Communities;
