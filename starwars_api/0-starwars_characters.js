#!/usr/bin/node

const request = require('request');

function fetch (url) {
  return new Promise((resolve, reject) => {
    request({ url, json: true }, (error, response, body) => {
      if (error) {
        return reject(error);
      }
      resolve(body);
    });
  });
}

if (process.argv[2]) {
  const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
  fetch(url).then(body => {
    const characterPromises = body.characters.map(characterUrl => fetch(characterUrl));

    Promise.all(characterPromises)
      .then(characters => {
        characters.forEach(character => {
          console.log(character.name); // Afficher le nom du personnage
        });
      })
      .catch(error => {
        console.error('Error fetching characters:', error);
      });
  })
    .catch(error => {
      console.error('Error fetching film:', error);
    });
} else {
  console.error('Error: Please provide a movie id - example: ./0-starwars_characters.js <1>');
}
