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
  const T = Number(readLine());
  var available = {};
  let hasSolution;
  for (let t = 0; t < T; t++) {
    let sol = '';
    hasSolution = true;
    let A = Number(readLine());
    let programs = [];
    for (let i = 0; i < A; i++) {
      programs.push(readLine());
    }
    let beaten = Array(A).fill(false);
    let currMove;
    let wins = 0;
    for (let j = 0; j < 500; j++) {
      available = {
        P: 0,
        R: 0,
        S: 0
      };
      for (let i = 0; i < A; i++) {
        if (!beaten[i]) {
          currMove = programs[i][j % programs[i].length];
          setAvailableHands(available, currMove);
        }
        if (available['P'] === -1 && available['R'] === -1 && available['S'] === -1) {
          hasSolution = false;
          break;
        }
      }
      if (!hasSolution) {
        sol = 'IMPOSSIBLE';
        break;
      } else {
        let max = ['P', 'R', 'S'].reduce((v, k) => {
          return Math.max(v, available[k]);
        }, -1);
        let maxKey = ['P', 'R', 'S'].find(k => available[k] === max);
        sol = sol + maxKey;
        for (let i = 0; i < A; i++) {
          if (!beaten[i]) {
            currMove = programs[i][j % programs[i].length];
            if (currMove != maxKey) {
              beaten[i] = true;
              wins++;
            }
          }
        }
      }
      if (wins === A) {
        break;
      }
    }

    console.log(`Case #${t + 1}: ${sol}`);
  }
}

function setAvailableHands(available, move) {
  if (move === 'P') {
    available['R'] = -1;
    if (available['S'] >= 0) {
      available['S']++;
    }
  }
  if (move === 'R') {
    available['S'] = -1;
    if (available['P'] >= 0) {
      available['P']++;
    }
  }
  if (move === 'S') {
    available['P'] = -1;
    if (available['R'] >= 0) {
      available['R']++;
    }
  }
}
