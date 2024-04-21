import LoginPage from './auth/login';
import { useState } from 'react';

function App() {
  const [language] = useState('en');

  return (
    <div className="App">
      <LoginPage language={language}/>
    </div>
  );
}
export default App;
