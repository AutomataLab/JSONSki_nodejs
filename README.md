# JSONSki
JSONSki_Nodejs is the Node.Js (Javascript) binding port for JSONSki

JSONSki is **a streaming JSONPath processor** with **fast-forward** functionality. During the streaming, it can automatically fast-forward over certain JSON substructures that are irrelavent to the query evaluation, without parsing them in detail. To make the fast-forward efficient, JSONSki features a highly bit-parallel solution that intensively utilizes bitwise and SIMD operations that are prevelent on modern CPUs to implement the fast-forward APIs. For more details about JSONSki, please refer to our paper [1].

## NPM Package
You can download the npm package from here - https://www.npmjs.com/package/jsonski

## Installation
```
npm i jsonski
```


## Hardware requirements
```
CPUs: 64-bit ALU instructions, 256-bit SIMD instruction set, and the carry-less multiplication instruction (pclmulqdq)
Operating System: Linux, MacOs (Intel Chips only) 
C++ Compiler: g++ (7.4.0 or higher)
```


## Software requirements

Before starting to use Node-API you need to assure you have the following prerequisites:

**Node.JS (v14 and above)** see: [Installing Node.js](https://nodejs.org/)

**Python (v3.7 and above)** see: [Installing Python](https://www.python.org/downloads/release/python-3100/)

**C++ : g++ (7.4.0 or higher)** see: [Installing C++](https://gcc.gnu.org/install/)




## Usage
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
This code snippet benchmarks performance for Javascript parsing VS  JSONSki_nodejs parsing.
We interface the following method:
```
JSki.JSONSkiParser(args1, args2)    //args1 - String(query) and args2 - String(file_location)
```
The function returns a javascript string as the output of the given query.
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

#### Supported Operators (to be updated)
| Operator                  |   Description     |
| :-----------------------: |:-----------------:|
| `$`                       | root object              |
| `.`                       | child object      |
| `[]`                       | child array      |
| `*`                       | wildcard, all objects or array members          |
| `[index]`             | array index      |
| `[start:end]`             | array slice operator      |


## Benchmarking 
Performance of JSONSki_nodejs is compared with simDjson_nodejs and Javascript Parsing  - https://github.com/gandharva26/benchmarking-jsonski



