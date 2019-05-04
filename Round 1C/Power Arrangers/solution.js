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
  let positions = [];
  let firstLetter = {
    A: 0,
    B: 0,
    C: 0,
    D: 0,
    E: 0
  };

  let sol = '';
  let leter;
  for (let i = 0; i < 119; i++) {
    console.log(i * 5 + 1);
    letter = await readLine();
    firstLetter[letter]++;
    positions.push({ p: i * 5 + 1, letter });
  }
  let candidate = ['A', 'B', 'C', 'D', 'E'].find(c => firstLetter[c] === 23);
  sol = sol + candidate;

  firstLetter = {
    A: 0,
    B: 0,
    C: 0,
    D: 0,
    E: 0
  };
  positions = positions.filter(p => p.letter === candidate);
  let next = [];
  for (let i = 0; i < 23; i++) {
    let pos = positions[i].p;
    console.log(pos + 1);
    letter = await readLine();
    firstLetter[letter]++;
    next.push({ p: pos + 1, letter });
  }

  candidate = ['A', 'B', 'C', 'D', 'E'].find(c => firstLetter[c] === 5);
  sol = sol + candidate;
  positions = [];
  firstLetter = {
    A: 0,
    B: 0,
    C: 0,
    D: 0,
    E: 0
  };
  next = next.filter(p => p.letter === candidate);
  for (let i = 0; i < 5; i++) {
    let pos = next[i].p;
    console.log(pos + 1);
    letter = await readLine();
    firstLetter[letter]++;
    positions.push({ p: pos + 1, letter });
  }
  candidate = ['A', 'B', 'C', 'D', 'E'].find(c => firstLetter[c] === 1);
  sol = sol + candidate;
  positions = positions.filter(p => p.letter === candidate);
  console.log(positions[0].p + 1);
  letter = await readLine();
  sol = sol + ['A', 'B', 'C', 'D', 'E'].find(c => c !== letter && !sol.includes(c)) + letter;
  console.log(sol);
}
