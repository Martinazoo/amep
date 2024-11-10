import React, { useState, useEffect, useContext } from 'react';
import { FaUsers, FaDoorOpen, FaClipboardList, FaScrewdriver, FaHandshake, FaHome, FaBars } from 'react-icons/fa';
import { useNavigate, useLocation } from 'react-router-dom';
import Cookies from 'js-cookie';
import { CommunityContext } from '../context/CommunityContext';
import styles from './NavBar.module.css';
import { FaUserEdit, FaTools, FaTrashAlt } from 'react-icons/fa';
import { FaPlus, FaTrash } from 'react-icons/fa6';

const NavBar = ({ type }) => {
  const navigate = useNavigate();
  const location = useLocation();
  const { selectedCommunity } = useContext(CommunityContext);
  const [activeItem, setActiveItem] = useState(location.pathname);
  const [isCollapsed, setIsCollapsed] = useState(false);
  const [isAdmin, setIsAdmin] = useState(false);

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

  const handleClick = (id, path) => {
    setActiveItem(path);
    navigate(path);
  };

  const handleToggle = () => {
    setIsCollapsed(!isCollapsed);
  };

  const navItems = {
    communities: [
      { id: 'lesTevesCom', icon: <FaUsers />, text: 'Les teves Comunitats', path: '/communities' },
      { id: 'crearCom', icon: <FaPlus/>, text: 'Crear Comunitat', path: '/crear-comunitat' },
    ],
    services: [
      { id: 'serveis', icon: <FaHome />, text: 'Serveis', path: '/services' },
      { id: 'veins', icon: <FaUsers />, text: 'Veïns', path: '/veins' },
      { id: 'tasques', icon: <FaClipboardList />, text: 'Tasca', path: '/tasques' },
      ...(isAdmin ? [{ id: 'administrador', icon: <FaScrewdriver />, text: 'Administrador', path: '/administrador' }] : []),
      { id: 'collaboracio', icon: <FaHandshake />, text: 'Col·laboració', path: '/colaboracio' },
      { id: 'comunitat', icon: <FaDoorOpen />, text: 'Comunitats', path: '/communities' },

    ],
    profile: [
      { id: 'editar', icon: <FaUserEdit />, text: 'Editar perfil', path: '/perfil/editar' },
      { id: 'serveis_meus', icon: <FaClipboardList />, text: 'Els teus serveis', path: '/perfil/serveis' },
      { id: 'eliminar', icon: <FaTrashAlt />, text: 'Esborrar usuari', path: '/perfil/esborrar' },
      { id: 'comunitat', icon: <FaDoorOpen />, text: 'Comunitats', path: '/communities' },
    ]
  };

  const items = navItems[type] || [];

  return (
    <div className={styles.navContainer}>
      <button onClick={handleToggle} className={styles.toggleButton}>
        <FaBars />
      </button>
      <nav className={`${styles.nav} ${isCollapsed ? styles.navCollapsed : ''}`}>
        <ul className={styles.navUl}>
          {items.map((item) => (
            <li 
              id={item.id} 
              key={item.id} 
              onClick={() => handleClick(item.id, item.path)} 
              className={`${styles.navLi} ${activeItem === item.path ? styles.navLiActive : ''}`}
            >
              <span className={styles.navLiIcon}>{item.icon}</span>
              {!isCollapsed && item.text}
            </li>
          ))}
        </ul>
      </nav>
    </div>
  );
};

export default NavBar;
