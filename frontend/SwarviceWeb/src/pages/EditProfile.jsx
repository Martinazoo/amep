import React, { useContext, useState } from 'react';
import { FaPlus } from 'react-icons/fa';
import NavBar from '../components/NavBar';
import Profile from '../components/Profile';
import EditUser from '../components/EditUser';

import ServeiForm from '../components/PublishService'; // Import the ServeiForm component
import '../pallette.css';
import '../Pagina.css';
import { CommunityContext } from '../context/CommunityContext'; // Import the context


const EditProfile = ({ onLogout }) => {


    return (
        <div className="page-container">
                 <NavBar type="profile" />
                 <div className="content-container">
                 <Profile onLogout={onLogout} />
                 <h1 id="title_communities">Edita el teu perfil</h1>
                 <div className="colaboracio-services-container"
                 style={{
                    
                    justifyContent: 'center'
                 }}>
                    <EditUser />

                </div>
            </div>
        </div>
    );
};

export default EditProfile;
