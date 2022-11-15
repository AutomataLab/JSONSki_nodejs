const JSki = require('./build/Release/JSONSki.node')
var fs = require('fs');
console.log("C++ JSONSKI")
console.time();
console.log('JsonSki Runtime', JSki.JSONSkiParser("$[*].entities.urls[*].url", "dataset/twitter_sample_large_record.json"));
console.timeEnd();
contents = fs.readFileSync('dataset/twitter_sample_large_record.json')
c = contents.toString()
console.log("Javascript Runtime ")
console.time();
var json = JSON.parse(c);
console.timeEnd();
module.exports = JSki;
