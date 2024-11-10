import React from 'react';
import Cookies from 'js-cookie';
import { FaUser, FaCoins, FaSignOutAlt } from 'react-icons/fa';
import { useNavigate } from 'react-router-dom';
import styles from './Profile.module.css';

const Profile = ({ onLogout }) => {
  const navigate = useNavigate();
  const username = Cookies.get('username');
  const tokens = Cookies.get('tokens'); // Assume que tens una cookie per als tokens

  const handleLogout = () => {
    onLogout();
    navigate('/login');
  };
  const handleProfile = () => {
    navigate('/perfil/editar')
  }

  return (
    <div className={styles.profile}>
      <div className={styles.userInfo} onClick={handleProfile}> 
        <FaUser className={styles.icon} />
        <span>{username}</span>
      </div>
      <div className={styles.userTokens}>
        <FaCoins className={styles.icon} />
        <span>{tokens}</span>
      </div>
      <button className={styles.logoutButton} onClick={handleLogout}>
        <FaSignOutAlt className={styles.icon} />
        Logout
      </button>
    </div>
  );
};

export default Profile;
