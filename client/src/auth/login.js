import React, { useState } from 'react';
import translate from '../i18n';
import './login.css'

const LoginPage = ({ language }) => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');

  const handleSubmit = (e) => {
    e.preventDefault();
    console.log('Email:', email);
    console.log('Password:', password);
  };

  const handleForgotPasswordClick = () => {
    console.log("Forgot pass");
  };

  const handleSignUpClick = () => {
    console.log("register");
  };

  return (
    <div>
      <h2>{translate(language, 'login')}</h2>
      <form onSubmit={handleSubmit}>
        <div>
          <label htmlFor="email">{translate(language, 'email')}:</label>
          <input
            type="email"
            id="email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            required
          />
        </div>
        <div>
          <label htmlFor="password">{translate(language, 'password')}:</label>
          <input
            type="password"
            id="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            required
          />
        </div>
        <button type="submit">{translate(language, 'login')}</button>
      </form>
      <div>
        <div className="links-container">
          <span className="forgot-password" onClick={handleForgotPasswordClick}>
            {translate(language, 'forgotPassword')}
          </span>
          <span className="sign-up" onClick={handleSignUpClick}>
            {translate(language, 'register')}
          </span>
        </div>
      </div>
    </div>
  );
};

export default LoginPage;
