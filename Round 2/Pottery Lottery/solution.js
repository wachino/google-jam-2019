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
  const T = Number(await readLine());
  for (let t = 0; t < T; t++) {
    await processTestCase();
  }
  rli.close();
  process.stdin.destroy();
}

async function processTestCase() {
  let vases = [];
  let day;
  for (let i = 0; i < 50; i++) {
    day = Number(await readLine());
    console.log(`${(i % 10) + 1} ${i < 10 ? 100 : day}`);
  }
  for (let i = 0; i < 10; i++) {
    await readLine();
    console.log(`${i + 1} ${0}`);
    vases.push({ vase: i + 11, votes: (await readLine()).slice(1) });
  }
  vases.sort((a, b) => b.votes.length - a.votes.length);
  for (let i = 0; i < 20; i++) {
    day = Number(await readLine());
    console.log(`${vases[i % 5].vase} ${i < 5 ? 100 : day}`);
  }
  vases = vases.slice(5);
  for (let i = 0; i < 5; i++) {
    await readLine();
    console.log(`${vases[i].vase} ${0}`);
    vases[i].votes = (await readLine()).slice(1);
  }
  vases.sort((a, b) => b.votes.length - a.votes.length);
  for (let i = 0; i < 9; i++) {
    day = Number(await readLine());
    console.log(`${vases[i % 3].vase} ${i < 3 ? 100 : day}`);
  }
  vases = vases.slice(3);
  for (let i = 0; i < 2; i++) {
    await readLine();
    console.log(`${vases[i].vase} ${0}`);
    vases[i].votes = (await readLine()).slice(1);
  }
  vases.sort((a, b) => b.votes.length - a.votes.length);
  for (let i = 0; i < 3; i++) {
    day = Number(await readLine());
    console.log(`${vases[0].vase} ${i < 1 ? 100 : day}`);
  }
  await readLine();
  console.log(`${vases[1].vase} ${100}`);
}
