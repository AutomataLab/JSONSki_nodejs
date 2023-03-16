[![CircleCI](https://circleci.com/gh/AutomataLab/JSONSki_nodejs.svg?style=shield&circle-token=daf002fef2464bc57675d6a3dc072485f27b7bbc)](https://app.circleci.com/pipelines/github/AutomataLab/JSONSki_nodejs)  ![GitHub](https://img.shields.io/github/license/AutomataLab/JSONSki_nodejs)
![npm](https://img.shields.io/npm/dt/jsonski?label=npm%20downloads)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/AutomataLab/jsonski_nodejs)
![](https://img.shields.io/badge/linux-macos-green)

# JSONSki_NodeJs
JSONSki_Nodejs is the Node.Js (Javascript) binding port for JSONSki

JSONSki is **a streaming JSONPath processor** with **fast-forward** functionality. During the streaming, it can automatically fast-forward over certain JSON substructures that are irrelavent to the query evaluation, without parsing them in detail. To make the fast-forward efficient, JSONSki features a highly bit-parallel solution that intensively utilizes bitwise and SIMD operations that are prevelent on modern CPUs to implement the fast-forward APIs. 

## NPM Package
You can download the npm package from here - https://www.npmjs.com/package/jsonski

## Installation
```
npm i jsonski
```

## Quick Start

```
const JSki = require('jsonski')
console.log(JSki.JSONSkiParser("$.features[150].actor.login", "datasets/test.json"));
```

- We interface the following method:
```
JSki.JSONSkiParser(args1, args2)    //args1 - String(query) and args2 - String(file_location)
```

## Requirements

### Hardware requirements

- CPUs: 64-bit ALU instructions, 256-bit SIMD instruction set, and the carry-less multiplication instruction (pclmulqdq)
- Operating System: Linux, MacOs (Intel Chips only) 
- C++ Compiler: g++ (7.4.0 or higher)


### Software requirements

Before starting to use Node-API you need to assure you have the following prerequisites:

- Node.JS (v14 and above) see: [Installing Node.js](https://nodejs.org/)

- Python (v3.9) see: [Installing Python](https://www.python.org/downloads/release/python-3100/)

- C++ : g++ (v7.4.0 and above) see: [Installing C++](https://gcc.gnu.org/install/)


## Getting Started with Querying using JSONSki
### JSONPath
JSONPath is the basic query language of JSON data. It refers to substructures of JSON data in a similar way as XPath queries are used for XML data. For the details of JSONPath syntax, please refer to [Stefan Goessner's article](https://goessner.net/articles/JsonPath/index.html#e2). 

#### JSONSki Queries Operators
| Operator                  |   Description     |
| :-----------------------: |:-----------------:|
| `$`                       | root object              |
| `.`                       | child object      |
| `[]`                       | child array      |
| `*`                       | wildcard, all objects or array members          |
| `[index]`             | array index      |
| `[start:end]`             | array slice operator      |


#### Path Examples
Consider a piece of geo-referenced tweet in JSON
```javascript
{
    "coordinates": [
        40.74118764, -73.9998279
    ],
    "user": {
        "id": 6253282
    },
    "place": {
        "name": "Manhattan",
        "bounding_box": {
            "type": "Ploygon",
            "pos": [
                [-74.026675, 40.683935],
                ......
            ]
        }
    }
}
```
| JsonPath | Result |
| :------- | :----- |
| `$.coordinates[*]` | all coordinates     |
| `$.place.name` | place name   |
| `$.place.bounding_box.pos[0]`| first position of the bounding box in place                      |
| `$.place.bounding_box.pos[0:2]`| first two positions of the bounding box in place                      |

## Performance Comparison with Javascript Parsing
Below is an example usage of Jsonski npm package. 
```
const JSki = require('jsonski')
const fs = require('fs');
console.time();
console.log('JsonSki Runtime', JSki.JSONSkiParser("$[*].entities.urls[*].url", "dataset/twitter_sample_large_record.json"));
console.timeEnd();

file_contents = fs.readFileSync('dataset/twitter_sample_large_record.json')
str = file_contents.toString()
console.log("Javascript Runtime")
console.time();
var json = JSON.parse(str);
console.timeEnd();
```
- Note: The code snippet above benchmarks performance for Javascript parsing VS  JSONSki_nodejs parsing.


## Publication
[1] Lin Jiang and Zhijia Zhao. [JSONSki: Streaming Semi-structured Data with Bit-Parallel Fast-Forwarding](https://dl.acm.org/doi/10.1145/3503222.3507719). In Proceedings of the Twenty-Third International Conference on Architectural Support for Programming Languages and Operating Systems (ASPLOS), 2022.
```
@inproceedings{jsonski,
  title={JSONSki: Streaming Semi-structured Data with Bit-Parallel Fast-Forwarding},
  author={Lin Jiang and Zhijia Zhao},
  booktitle={Proceedings of the Twenty-Third International Conference on Architectural Support for Programming Languages and Operating Systems (ASPLOS)},
  year={2022}
}
```

## Performance

![image](https://user-images.githubusercontent.com/55717003/208404929-49e0c162-77ff-4330-b579-ac5083aa1cb9.png)


## Benchmarking 
Performance of JSONSki_nodejs is compared with simdjson_nodejs and Javascript Parsing  - https://github.com/AutomataLab/NPM-JSON-Parser-Benchmarking



