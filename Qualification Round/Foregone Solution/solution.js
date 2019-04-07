const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString
    .trim()
    .split('\n')
    .map(str => str.trim());
  solution();
});

function readLine() {
  return inputString[currentLine++];
}

function solution() {
  const t = Number(readLine());
  for (let i = 0; i < t; i++) {
    let N = readLine();
    let A = [];
    let B = [];
    for (let j = N.length - 1; j >= 0; j--) {
      let isFour = N[j] === '4';
      A.push(isFour ? '2' : N[j]);
      B.push(isFour ? '2' : '0');
    }
    A.reverse();
    B.reverse();
    let leadingZeros = 0;
    let k = 0;
    while (B[k] === '0') {
      k++;
    }
    A = A.join('');
    B = B.slice(k).join('');
    console.log(`Case #${i + 1}: ${A} ${B}`);
  }
}
