import React from 'react';
import styles from './CommunityItem.module.css';

const CommunityItem = ({ community, delay , onClick}) => {
  const handleClick = () => {
    console.log(community.name);
  };

  return (
    <div onClick={onClick} className={styles.community} style={{ animationDelay: `${delay}s` }}>
      <a className={styles.communityTitle}>{community.name}</a>
      <hr className={styles.communityHr} />
      <a className={styles.communityDescription}>{community.description}</a>
    </div>
  );
};

export default CommunityItem;
