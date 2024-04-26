#!/usr/bin/node

const request = require('request');

if (process.argv[2]) {
	const url = `https://swapi-api.hbtn.io/api/films/` + process.argv[2];
	request({url: url, json: true }, function (error, response, body) {
		for (let i = 0; i < body.characters.length; i++) {
			let urlCharacters = body.characters[i].toString();
			request({ url: urlCharacters, json: true }, function (error, response, body) {
				console.log(body.name)
			})
		}
	});
}
else {
	console.error("error: Please give an movie id - example : ./0-starwars_characters.js <1> ");
}
