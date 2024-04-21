import fr from './lang/fr.json';
import en from './lang/en.json';

const languages = {
  fr,
  en
};

export default function translate(language, key) {
  return languages[language][key] || '';
}
