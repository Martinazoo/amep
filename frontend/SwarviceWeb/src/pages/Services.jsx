import React, { useContext, useEffect, useState } from 'react';
import { FaPlus } from 'react-icons/fa';
import NavBar from '../components/NavBar';
import Profile from '../components/Profile';
import ServicesList from '../components/ServicesList';
import ServicesFilter from '../components/ServicesFilter';
import ServeiForm from '../components/PublishService';
import '../pallette.css';
import '../Pagina.css';
import { CommunityContext } from '../context/CommunityContext';
import Cookies from 'js-cookie';

const Services = ({ onLogout }) => {
  const { selectedCommunity } = useContext(CommunityContext);
  const [showForm, setShowForm] = useState(false);
  const [services, setServices] = useState([]);

  const handlePlusIconClick = () => {
    setShowForm(true);
  };

  const handleCancel = () => {
    setShowForm(false);
  };

  const handleFilter = (filteredData) => {
    setServices(filteredData);
  };

  useEffect(() => {
    const fetchServices = async () => {
      console.log('Fetching services...'); // Debugging log
      const username = Cookies.get('username');
      console.log('Selected Community:', selectedCommunity.id); // Debugging log
      console.log('Username:', username); // Debugging log
      const dataJSON = {
        community: selectedCommunity.name,
        username: username,
      };
      console.log('Data JSON:', dataJSON); // Debugging log

      
      try {
        const response = await fetch('/apiConsultServices.json', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify(dataJSON),
        });
  
        const data = await response.json();
        console.log('Services Data:', data); // Debugging log
        setServices(data.serveis);
      } catch (error) {
        console.error('There was a problem with the fetch operation:', error);
      }
    }; // Add closing parenthesis here

    if (selectedCommunity) {
      fetchServices();
    }
  }, [selectedCommunity]);


  return (
    <div className="page-container">
      <NavBar type="services" />
      <div className="content-container">
        <Profile onLogout={onLogout} />
        <h1 id="title_communities">{selectedCommunity?.name}</h1>
        {showForm ? (
          <ServeiForm onCancel={handleCancel} />
        ) : (
          <>
            <ServicesFilter onFilter={handleFilter}/>
            <ServicesList serveis={services} />
          </>
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

export default Services;
