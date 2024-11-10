import React from 'react';
import './Card.css';

const ErrorCard = ({ tittle, body, type }) => {

  if(type == "error"){
    return (
      <div className="error">
        <h2>{tittle}</h2>
        <p>{body}</p>
      </div>
    );
  } else {
    return (
      <div className="card">
        <h2>{tittle}</h2>
        <p>{body}</p>
      </div>
    );
  }

}

export default ErrorCard;