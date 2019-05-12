const rl = require('readline');

const rli = rl.createInterface({
  input: process.stdin,
  output: process.stdout,
  crlfDelay: Infinity
});

async function* getLineGenerator() {
  for await (const line of rli) {
    yield line;
  }
}
const lineGenerator = getLineGenerator();

async function readLine() {
  const line = await lineGenerator.next();
  return line.value;
}

solve();

async function solve() {
  const [T, F] = (await readLine()).split(' ').map(Number);

  for (let t = 0; t < T; t++) {
    await processTestCase();
    let veredict = await readLine();
  }
  rli.close();
  process.stdin.destroy();
}

async function processTestCase() {
  const allPowerArrangers = ['A', 'B', 'C', 'D', 'E'];
  let countFirstLetter = {};
  let positions = Array(120)
    .fill(0)
    .map((_, id) => ({ p: id * 5 }));
  let next = [];
  let totalComb = 120;
  let sol = '';
  for (let j = 5; j > 0; j--) {
    next = [];
    countFirstLetter = {};
    allPowerArrangers.filter(p => !sol.includes(p)).forEach(p => (countFirstLetter[p] = 0));
    for (let i = 0; i < totalComb - 1; i++) {
      let pos = positions[i].p;
      console.log(pos + 1);
      letter = await readLine();
      countFirstLetter[letter]++;
      next.push({ p: pos + 1, letter });
    }
    totalComb /= j;
    candidate = allPowerArrangers.find(c => countFirstLetter[c] === totalComb - 1);
    sol += candidate;
    positions = next.filter(p => p.letter === candidate);
  }
  console.log(sol);
}
