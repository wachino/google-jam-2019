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

let sol = 0;
function solution() {
  const T = Number(readLine());
  for (let t = 0; t < T; t++) {
    let board = [];
    let [R, C] = readLine()
      .split(' ')
      .map(Number);

    for (let i = 0; i < R; i++) {
      board.push(
        readLine()
          .trim()
          .split('')
          .map(c => (c === '.' ? 0 : 1))
      );
    }
    let nimber = Array(16)
      .fill(0)
      .map(() =>
        Array(16)
          .fill(0)
          .map(() =>
            Array(16)
              .fill(0)
              .map(() => Array(16).fill(0))
          )
      );
    sol = 0;
    getNumberOfWinningMoves(board, nimber, 0, 0, R, C, R, C);
    console.log(`Case #${t + 1}: ${sol}`);
  }
}

function getNumberOfWinningMoves(board, nimber, ai, aj, bi, bj, R, C) {
  return getNumberOfWinningMovesAux(ai, aj, bi, bj);
  function getNumberOfWinningMovesAux(ai, aj, bi, bj) {
    if (ai === bi || aj === bj) {
      return 0;
    }
    if (nimber[ai][aj][bi][bj]) {
      return nimber[ai][aj][bi][bj] - 1;
    }
    let states = [];
    for (let i = ai; i < bi; i++) {
      let ok = true;
      for (let j = aj; j < bj; j++) {
        if (board[i][j]) {
          ok = false;
        }
      }
      if (ok) {
        states.push(
          getNumberOfWinningMovesAux(ai, aj, i, bj) ^ getNumberOfWinningMovesAux(i + 1, aj, bi, bj)
        );
        if (ai === 0 && bi === R && aj === 0 && bj === C && states[states.length - 1] == 0) {
          sol += bj - aj;
        }
      }
    }
    for (let j = aj; j < bj; j++) {
      let ok = true;
      for (let i = ai; i < bi; i++) {
        if (board[i][j]) {
          ok = false;
        }
      }
      if (ok) {
        states.push(
          getNumberOfWinningMovesAux(ai, aj, bi, j) ^ getNumberOfWinningMovesAux(ai, j + 1, bi, bj)
        );
        if (ai === 0 && bi === R && aj === 0 && bj === C && states[states.length - 1] == 0) {
          sol += bi - ai;
        }
      }
    }
    states.sort((a, b) => a - b);
    let f = 0;
    for (let i = 0; i < states.length; i++) {
      if (states[i] === f) {
        f++;
      } else if (states[i] > f) {
        break;
      }
    }
    nimber[ai][aj][bi][bj] = f + 1;
    return f;
  }
}
