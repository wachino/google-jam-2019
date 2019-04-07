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
    let N = Number(readLine());
    let P = readLine();
    let sol = P.split('')
      .map(c => (c === 'E' ? 'S' : 'E'))
      .join('');
    console.log(`Case #${i + 1}: ${sol}`);
  }
}
