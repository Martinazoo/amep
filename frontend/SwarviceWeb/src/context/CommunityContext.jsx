// src/context/CommunityContext.js
import React, { createContext, useState } from 'react';

export const CommunityContext = createContext();

export const CommunityProvider = ({ children }) => {
  const [selectedCommunity, setSelectedCommunity] = useState(null);

  return (
    <CommunityContext.Provider value={{ selectedCommunity, setSelectedCommunity }}>
      {children}
    </CommunityContext.Provider>
  );
};
