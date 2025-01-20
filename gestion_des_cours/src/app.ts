import express from 'express';
import { json } from 'body-parser';
import routes from './routes'; // Assurez-vous d'avoir un fichier de routes

const app = express();
const PORT = process.env.PORT || 3000;

// Middleware
app.use(json());

// Routes
app.use('/api', routes);

// Démarrer le serveur
app.listen(PORT, () => {
    console.log(`Serveur en cours d'exécution sur le port ${PORT}`);
});