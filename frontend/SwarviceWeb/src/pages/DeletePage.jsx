import React, { useContext, useState } from 'react';
import { FaPlus } from 'react-icons/fa';
import NavBar from '../components/NavBar';
import Profile from '../components/Profile';
import ServicesList from '../components/ServicesList';
import ServeiForm from '../components/PublishService'; // Import the ServeiForm component
import '../pallette.css';
import '../Pagina.css';
import { CommunityContext } from '../context/CommunityContext'; // Import the context
import DeleteNeighbor from '../components/DeleteNeighbor';

const DeletePage = ({ onLogout }) => {
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
        <DeleteNeighbor/>
      </div>
    </div>
  );
};

export default DeletePage;
