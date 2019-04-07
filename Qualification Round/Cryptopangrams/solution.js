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
    const [N, L] = readLine()
      .split(' ')
      .map(Number);
    const ciphertext = readLine()
      .split(' ')
      .map(BigInt);

    const msg = [];
    for (let j = 0; j < L - 1; j++) {
      const g = gcd(ciphertext[j], ciphertext[j + 1]);
      let isEqual = ciphertext[j] === ciphertext[j + 1];
      msg.push(isEqual ? -1 : g);
    }
    let menosUno = msg.indexOf(-1);
    while (menosUno > -1) {
      if (menosUno > 0) {
        msg[menosUno] = ciphertext[menosUno] / msg[menosUno - 1];
        while (menosUno < msg.length - 1 && msg[menosUno + 1] === -1) {
          menosUno++;
          msg[menosUno] = ciphertext[menosUno] / msg[menosUno - 1];
        }
      } else {
        while (msg[menosUno + 1] === -1) {
          menosUno++;
        }
        msg[menosUno] = ciphertext[menosUno] / msg[menosUno + 1];

        while (menosUno > 0 && msg[menosUno - 1] === -1) {
          menosUno--;
          msg[menosUno] = ciphertext[menosUno] / msg[menosUno + 1];
        }
      }
      menosUno = msg.indexOf(-1);
    }
    msg.push(ciphertext[ciphertext.length - 1] / msg[msg.length - 1]);
    msg.unshift(ciphertext[0] / msg[0]);

    const abc = [...new Set([...msg])].sort((a, b) => (a < b ? -1 : 1));

    const sol = msg.map(c => String.fromCharCode('A'.charCodeAt(0) + abc.indexOf(c)));

    console.log(`Case #${i + 1}: ${sol.join('')}`);
  }
}

function gcd(a, b) {
  if (!b) {
    return a;
  }

  return gcd(b, a % b);
}
