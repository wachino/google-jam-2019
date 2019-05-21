process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

const MOD = 1000000007n;
const INF = -2n;

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
  for (let t = 0; t < T; t++) {
    let M = Number(readLine());
    let metals = [];
    let amount = [];
    let traspose = Array(M)
      .fill(false)
      .map(() => []);
    let reachable = Array(M).fill(false);
    let dp = Array(M).fill(-1n);
    dp[0] = 1n;
    for (let i = 0; i < M; i++) {
      let [a, b] = readLine()
        .split(' ')
        .map(Number);
      metals.push([a - 1, b - 1]);
      traspose[metals[i][0]].push(i);
      traspose[metals[i][1]].push(i);
    }

    checkReachable(reachable, traspose, 0);
    for (let i = 1; i < M; i++) {
      computePathsFrom(dp, metals, reachable, i);
    }

    if (
      dp[metals[0][0]] === INF ||
      dp[metals[0][1]] === INF ||
      dp[metals[0][0]] + dp[metals[0][1]] >= 2n
    ) {
      for (let i = 0; i < M; i++) {
        if (reachable[i]) {
          dp[i] = INF;
        }
      }
    }
    amount = readLine()
      .split(' ')
      .map(BigInt);
    let bounded = true;
    let sol = 0n;
    for (let i = 0; i < M; i++) {
      if (!bounded) {
        continue;
      }
      if (amount[i]) {
        if (dp[i] === INF) {
          bounded = false;
        } else {
          sol = (sol + ((amount[i] * dp[i]) % MOD)) % MOD;
        }
      }
    }
    if (bounded) {
      console.log(`Case #${t + 1}: ${sol % MOD}`);
    } else {
      console.log(`Case #${t + 1}: UNBOUNDED`);
    }
  }
}

function checkReachable(reachable, traspose, node) {
  let queue = [node];
  let j = 0;
  while (j < queue.length) {
    let next = queue[j++];
    if (!reachable[next]) {
      reachable[next] = true;
      for (let i = 0; i < traspose[next].length; i++) {
        queue.push(traspose[next][i]);
      }
    }
  }
}

function computePathsFrom(dp, metals, reachable, node) {
  let inCurrentPath = Array(metals.length).fill(false);

  let queue = [node];
  inCurrentPath[node] = true;
  let i = queue.length;
  while (i > 0) {
    let n = queue[i - 1];
    if (dp[n] >= 0n || dp[n] === INF) {
      i--;
      inCurrentPath[n] = false;
      continue;
    } else if (!reachable[n]) {
      dp[n] = 0n;
      i--;
      inCurrentPath[n] = false;
      continue;
    }

    let a = dp[metals[n][0]];
    let b = dp[metals[n][1]];
    if (a === -1n) {
      if (inCurrentPath[metals[n][0]]) {
        dp[metals[n][0]] = INF;
      } else {
        inCurrentPath[metals[n][0]] = true;
        if (queue.length >= i) {
          queue[i] = metals[n][0];
        } else {
          queue.push(metals[n][0]);
        }
        i++;
      }
      continue;
    }
    if (b === -1n) {
      if (inCurrentPath[metals[n][1]]) {
        dp[metals[n][1]] = INF;
      } else {
        inCurrentPath[metals[n][1]] = true;
        if (queue.length >= i) {
          queue[i] = metals[n][1];
        } else {
          queue.push(metals[n][1]);
        }
        i++;
      }
      continue;
    }
    if (a === -1n || b === -1n) {
      continue;
    }

    let tmp;
    if (a === INF || b === INF) {
      tmp = INF;
    } else {
      tmp = a + b;
      if (tmp > MOD + 2n) {
        tmp = tmp % MOD;
      }
    }
    dp[n] = tmp;
  }
  return dp[node];
}
