import React, { useState, useContext, useEffect } from 'react';
import './ServicesFilter.css';
import { CommunityContext } from '../context/CommunityContext'; // Assegura't que el camí és correcte
import { ETIQUETES } from '../constants/constants';
import Cookies from 'js-cookie';

const ServicesFilter = ({ onFilter }) => {
    
    const { selectedCommunity } = useContext(CommunityContext); // Accedir al context
    const [minVal, setMinVal] = useState(0);
    const [maxVal, setMaxVal] = useState(30);
    const min = 0;
    const max = 300;

    const [description, setDescription] = useState('');
    const [label, setEtiqueta] = useState('Totes');
  
    const handleMinChange = (event) => {
      const value = Math.min(Number(event.target.value), maxVal - 1);
      setMinVal(value);
    };
  
    const handleMaxChange = (event) => {
      const value = Math.max(Number(event.target.value), minVal + 1);
      setMaxVal(value);
    };

    //Formulari


    const handleFormSubmit = async (e) => {
        e.preventDefault();
        const formData = {
            description,
            label,
            minVal,
            maxVal
        };

        const dataToSend = {
            ...formData,
            community: selectedCommunity.id,
            username: Cookies.get('username'),
        };

        console.log(JSON.stringify(dataToSend))
        const response = await fetch('./apiFilterServices.json', {
            method: 'POST',
            headers: {
              'Content-Type': 'application/json',
            },
            body: JSON.stringify(dataToSend),
          });
        const data = await response.json();
        console.log(data.serveis);
        onFilter(data.serveis);
    };
    
    
    return(
        <>
        <div className='box'>            
            <p className="Filtrar">Filtrar:</p>
            <form className='Formulari' onSubmit={handleFormSubmit}>
                <div>
                    <label className='LabelText'>Descripció:</label>
                    <input className="NameText" type="text" name="Nom" onChange={(e) => setDescription(e.target.value)} placeholder='Descripció...' id="" />
                </div>
                <div>
                    <label className='LabelText' for="Etiqueta">Etiqueta:</label>
                    <select className='EtiquetaSelect' id="Etiqueta" onChange={(e) => setEtiqueta(e.target.value)}>
                    {Object.values(ETIQUETES).map((label) => (
                    <option value={label} key={label}>
                        {label}
                    </option>
                    ))}
                    </select>
                </div>
                <div className='Tokens'>
                    <label className='LabelText'>Tokens:</label>
                    <div className="dual-range-slider">
                        <input
                            type="range"
                            min={min}
                            max={max}
                            value={minVal}
                            onChange={handleMinChange}
                            style={{ zIndex: minVal > max - 10 ? '5' : '0' }}
                            className="thumb thumb--left"
                        />
                        <input
                            type="range"
                            min={min}
                            max={max}
                            value={maxVal}
                            onChange={handleMaxChange}
                            style={{ zIndex: minVal > max - 10 ? '5' : '0' }}
                            className="thumb thumb--right"
                        />
                        <div className="slider">
                            <div className="slider__track"></div>
                            <div className="slider__range" style={{ left: `${(minVal/max)*100}%`, right: `${((max-maxVal)/max)*100}%` }}></div>
                            <div className="slider__left-value">{minVal}</div>
                            <div className="slider__right-value">{maxVal}</div>
                        </div>
                    </div>
                </div>
                <input className='submit' type="submit" value="Filtrar"/>
            </form>
        </div>
        </>
    )
}

export default ServicesFilter;
