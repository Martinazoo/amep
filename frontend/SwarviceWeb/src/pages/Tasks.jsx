import React, { useContext } from 'react';
import { FaTrash } from 'react-icons/fa';
import NavBar from '../components/NavBar';
import { useNavigate } from 'react-router-dom';
import Profile from '../components/Profile';
import '../pallette.css';
import '../Pagina.css';
import Cookies from 'js-cookie';
import { CommunityContext } from '../context/CommunityContext'; // Import the context
import PendentTasksList from '../components/PendentTasksList';

const Tasks = ({ onLogout }) => {
  const { selectedCommunity } = useContext(CommunityContext); // Use context
  const navigate = useNavigate();

  return (
    <div className="page-container">
      <NavBar type="services" />
      <div className="content-container">
        <Profile onLogout={onLogout} />
        <h1 id="title_communities">{selectedCommunity?.name}</h1>
        <PendentTasksList />
       

      </div>
    </div>
  );
};

export default Tasks;
