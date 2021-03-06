const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  crlfDelay: Infinity
});

async function* getGenerator() {
  for await (const line of rl) {
    yield line;
  }
}
const generator = getGenerator();

async function solve() {
  let line = await generator.next();
  const t = Number(line.value);
  for (let i = 0; i < t; i++) {
    line = await generator.next();
    let [N, B, F] = line.value
      .trim()
      .split(' ')
      .map(Number);

    const answer = await findAnswer(N, B);
    console.log(answer.join(' '));
    line = await generator.next();
    let veredict = Number(line.value);
  }
  rl.close();
  process.stdin.destroy();
}

async function findAnswer(n, b) {
  const nums = Array(n)
    .fill(0)
    .map((_, i) => i % 32);
  let ans = Array(n - b).fill(0);
  for (let i = 4; i >= 0; i--) {
    console.log(nums.map(d => (d & (1 << i) ? 1 : 0)).join(''));
    let tmp = await generator.next();
    tmp = tmp.value.split('').map(Number);
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

solve();
