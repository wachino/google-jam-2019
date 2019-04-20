const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  crlfDelay: Infinity
});

async function ask(q = '') {
  return new Promise(solve => {
    rl.question(q, response => solve(response));
  });
}
/* rl.on('line', function(cmd) {
  debugger;
  console.log('You just typed: ' + cmd);
});
 */
rl.question('', async firstLine => {
  const t = Number(firstLine);
  for (let i = 0; i < t; i++) {
    let caseInfo = await ask();
    let [N, B, F] = caseInfo
      .trim()
      .split(' ')
      .map(Number);

    const answer = await findAnswer(N, B);

    let veredict = await ask(answer.join(' ') + '\n');
  }
  rl.close();
  process.stdin.destroy();
});

async function findAnswer(n, b) {
  const nums = Array(n)
    .fill(0)
    .map((_, i) => i % 32);
  let ans = Array(n - b).fill(0);
  for (let i = 4; i >= 0; i--) {
    let tmp = await ask(nums.map(d => (d & (1 << i) ? 1 : 0)).join('') + '\n');
    tmp = tmp.split('').map(Number);
    ans = ans.map((d, a) => (d << 1) | tmp[a]);
  }
  const ret = [];
  let k = 0;
  for (let i = 0; i < n; i++) {
    if (i % 32 !== ans[k]) {
      ret.push(i);
    } else {
      k++;
    }
  }
  if (b !== ret.length) {
    throw 'Wrong number of detected failing servers';
  }
  return ret;
}
