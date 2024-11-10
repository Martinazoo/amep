import React, { useContext, useState } from 'react';
import { FaPlus } from 'react-icons/fa';
import NavBar from '../components/NavBar';
import Profile from '../components/Profile';
import ServicesList from '../components/ServicesList';
import ServicesFilter from '../components/ServicesFilter';
import YourServicesList from '../components/YourServicesList';
import ServeiForm from '../components/PublishService'; // Import the ServeiForm component
import '../pallette.css';
import '../Pagina.css';
import { CommunityContext } from '../context/CommunityContext'; // Import the context
import EditService from '../components/modifyService';

const ProfileServices = ({ onLogout }) => {
    const [editForm, setEditForm] = useState(false);
    const [service, setService] = useState({});

    const handleEdit = (s) => {
        console.log('uyu');
        setEditForm(true);
        setService(s);
        console.log(s);
        console.log(service);

        
    }

    return (
        <div className="page-container">
            <NavBar type="profile" />
            <div className="content-container">
                <Profile onLogout={onLogout} />
                <h1 id="title_communities">Els teus serveis acceptats</h1>
                <div className="colaboracio-services-container">
                    <div className="colaboracio-services-list">
                    {editForm ? (
                            <EditService service={service} />
                        ) : (
                            <YourServicesList status="accepted" onEdit={handleEdit} />
                        )}

                    </div>

                </div>
            </div>
        </div>
    );
};

export default ProfileServices;
