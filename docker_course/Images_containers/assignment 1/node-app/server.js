const express = require('express');

const app = express();

app.get('/', (req, res) => {
  res.send(`
    <h1>Hello from inside the very basic Node app!</h1>
    <h2>hellllllo</h2>
  `);
})

app.listen(3000);