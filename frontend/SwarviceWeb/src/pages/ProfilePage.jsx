import React, { useContext, useState } from 'react';
import { FaPlus } from 'react-icons/fa';
import NavBar from '../components/NavBar';
import Profile from '../components/Profile';
import ServicesList from '../components/ServicesList';
import ServeiForm from '../components/PublishService'; // Import the ServeiForm component
import '../pallette.css';
import '../Pagina.css';
import { CommunityContext } from '../context/CommunityContext'; // Import the context

const InfoPerfil = ({ onLogout }) => {
  const { selectedCommunity } = useContext(CommunityContext); // Use context
  const [showForm, setShowForm] = useState(false); // State to toggle between ServicesList and ServeiForm

  const handlePlusIconClick = () => {
    setShowForm(true);
  };

  const handleCancel = () => {
    setShowForm(false);
  };

  return (
    <div className="page-container">
      <NavBar type="profile" />
      <div className="content-container">
        <Profile onLogout={onLogout} />
        <h1 id="title_communities">{selectedCommunity?.name}</h1>
        {showForm ? (
          <ServeiForm onCancel={handleCancel} />
        ) : (
          <ServicesList community={selectedCommunity} />
        )}
        {!showForm && (
          <div className="plus-icon" onClick={handlePlusIconClick}>
            <FaPlus />
          </div>
        )}
      </div>
    </div>
  );
};

export default InfoPerfil;
