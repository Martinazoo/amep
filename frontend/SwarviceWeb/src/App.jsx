import './App.css';
import { useState, useEffect } from 'react';
import { BrowserRouter as Router, Route, Routes, Navigate } from 'react-router-dom';
import Cookies from 'js-cookie';
import Login from './pages/Login';
import Register from './pages/Register'; // Importa el nou component Register
import Communities from './pages/Communities';
import Services from './pages/Services';
import Administrador from './pages/Administrador';
import CreateCommunity from './pages/CreateCommunity'; // Importa el nou component CreateCommunity
import Neighbors from './pages/Neighbors'; // Importa el nou component Neighbors
import { CommunityProvider } from './context/CommunityContext'; // Import the CommunityProvider
import Colaboracio from './pages/Collaboration'; // Importa el nou component Colaboracio
import Tasks from './pages/Tasks'; // Importa el nou component Tasks
import InfoPerfil from './pages/ProfilePage';
import DeleteNeighbor from './components/DeleteNeighbor';
import DeletePage from './pages/DeletePage';
import ProfileServices from './pages/ProfileServices';
import EditProfile from './pages/EditProfile';

function App() {
  const [isLoggedIn, setIsLoggedIn] = useState(Cookies.get('sessionToken') !== undefined);

  useEffect(() => {
    const sessionToken = Cookies.get('sessionToken');
    if (sessionToken) {
      setIsLoggedIn(true);
    } else {
      setIsLoggedIn(false);
    }
  }, []);

  const handleLoginSuccess = () => {
    Cookies.set('sessionToken', 'token-value', { expires: 7 }); // Expires in 7 days
    setIsLoggedIn(true);
  };

  const handleLogout = () => {
    Cookies.remove('sessionToken');
    Cookies.remove('username');
    Cookies.remove('password');
    Cookies.remove('tokens');
    Cookies.remove('dni');
    setIsLoggedIn(false);
  };

  return (
    <CommunityProvider> {/* Wrap the application with the provider */}
      <Router>
        <Routes>
          <Route path="/login" element={isLoggedIn ? <Navigate to="/communities" /> : <Login onLoginSuccess={handleLoginSuccess} />} />
          <Route path="/register" element={isLoggedIn ? <Navigate to="/communities" /> : <Register />} /> {/* Afegeix la nova ruta */}
          <Route path="/communities" element={isLoggedIn ? <Communities onLogout={handleLogout} /> : <Navigate to="/login" />} />
          <Route path="/services" element={isLoggedIn ? <Services onLogout={handleLogout} /> : <Navigate to="/login" />} />
          <Route path="/administrador" element={isLoggedIn ? <Administrador onLogout={handleLogout} /> : <Navigate to="/login" />} />
          <Route path="/colaboracio" element={isLoggedIn ? <Colaboracio onLogout={handleLogout} /> : <Navigate to="/login" />} />
          <Route path="/crear-comunitat" element={isLoggedIn ? <CreateCommunity onLogout={handleLogout} /> : <Navigate to="/login" />} />
          <Route path="/veins" element={isLoggedIn ? <Neighbors onLogout={handleLogout} /> : <Navigate to="/login" />} />
          <Route path="/tasques" element={isLoggedIn ? <Tasks onLogout={handleLogout} /> : <Navigate to="/login" />} />
          <Route path="/perfil" element={isLoggedIn ? <InfoPerfil onLogout={handleLogout} /> : <Navigate to="/login" />} />
          
          <Route path="/perfil/esborrar"  element = {<DeletePage Logout={handleLogout} /> } />
          <Route path="/perfil/serveis"  element = {<ProfileServices Logout={handleLogout} /> } />
          <Route path="/perfil/editar"  element = {<EditProfile Logout={handleLogout} /> } />
          <Route path="/" element={<Navigate to={isLoggedIn ? "/communities" : "/login"} />} />
        </Routes>
      </Router>
    </CommunityProvider>
  );
}

export default App;
