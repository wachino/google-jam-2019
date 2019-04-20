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

class RNG {
  constructor(seed) {
    this.m = 0x80000000; // 2**31;
    this.a = 1103515245;
    this.c = 12345;
    this.state = seed ? seed : Math.floor(Math.random() * (this.m - 1));
  }
  nextInt() {
    this.state = (this.a * this.state + this.c) % this.m;
    return this.state;
  }
}

const rng = new RNG(1);

function readLine() {
  return inputString[currentLine++];
}

function solution() {
  const precalculatedPaths = getPrecalculatedPaths();
  const t = Number(readLine());
  for (let i = 0; i < t; i++) {
    var [R, C] = readLine()
      .split(' ')
      .map(c => c.trim())
      .map(Number);

    let isPossible = precalculatedPaths[R][C].length > 0;
    console.log(`Case #${i + 1}: ${isPossible ? 'POSSIBLE' : 'IMPOSSIBLE'}`);
    if (isPossible) {
      printPath(precalculatedPaths[R][C]);
    }
  }
}

function getPrecalculatedPaths() {
  const precalculatedPaths = Array(21)
    .fill(0)
    .map(() => Array(21).fill([]));

  for (let R = 2; R <= 20; R++) {
    for (let C = 2; C <= 20; C++) {
      var visited = Array(R)
        .fill(false)
        .map(() => Array(C).fill(false));
      var canGoTo = getAvailableJumps(R, C);
      var currentPath = [];
      for (let r = 0; r < R; r++) {
        for (let c = 0; c < C; c++) {
          visited[r][c] = true;
          currentPath = [{ r, c }];
          doBacktracking({ r, c }, 1);
          visited[r][c] = false;
        }
      }

      function doBacktracking(current, steps) {
        if (precalculatedPaths[R][C].length) {
          return;
        }
        for (let i = 0; i < canGoTo[current.r][current.c].length; i++) {
          let { r, c } = canGoTo[current.r][current.c][i];
          if (!visited[r][c]) {
            visited[r][c] = true;
            currentPath.push({ r, c });
            if (steps + 1 === R * C) {
              precalculatedPaths[R][C] = currentPath.slice();
              return;
            } else {
              doBacktracking({ r, c }, steps + 1);
            }
            currentPath.pop();
            visited[r][c] = false;
          }
        }
      }
    }
  }

  return precalculatedPaths;
}

function getAvailableJumps(R, C) {
  const canGoTo = [];
  for (let rFrom = 0; rFrom < R; rFrom++) {
    canGoTo.push([]);
    for (let cFrom = 0; cFrom < C; cFrom++) {
      canGoTo[rFrom].push([]);
      for (let rTo = 0; rTo < R; rTo++) {
        for (let cTo = 0; cTo < C; cTo++) {
          if (
            rFrom !== rTo &&
            cFrom !== cTo &&
            rFrom - cFrom !== rTo - cTo &&
            rFrom + cFrom !== rTo + cTo
          ) {
            canGoTo[rFrom][cFrom].push({ r: rTo, c: cTo });
          }
        }
      }
      shuffle(canGoTo[rFrom][cFrom]);
    }
  }
  return canGoTo;
}

function printPath(path) {
  for (let p = 0; p < path.length; p++) {
    console.log(`${path[p].r + 1} ${path[p].c + 1}`);
  }
}

function shuffle(arr) {
  let currentIndex = arr.length;
  let temporaryValue;
  let randomIndex;

  while (0 !== currentIndex) {
    randomIndex = rng.nextInt() % currentIndex;
    currentIndex--;

    temporaryValue = arr[currentIndex];
    arr[currentIndex] = arr[randomIndex];
    arr[randomIndex] = temporaryValue;
  }

  return arr;
}
