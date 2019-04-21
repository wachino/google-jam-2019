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
  debugger;
  const [T, N, M] = (await readLine()).split(' ').map(Number);

  const coprimes = [5, 7, 9, 11, 13, 16, 17];
  const numbers = [];
  let product = 1;
  const casesNumbers = [];

  for (let i = 0; i < coprimes.length; i++) {
    product *= coprimes[i];
    numbers.push(coprimes[i]);

    casesNumbers.push(Array(18).fill(coprimes[i]));

    if (product >= M) {
      break;
    }
  }

  for (let t = 0; t < T; t++) {
    await processTestCase(numbers, casesNumbers);
    let veredict = Number(await readLine());
  }
  rli.close();
  process.stdin.destroy();
}

async function processTestCase(numbers, casesNumbers) {
  let reminders = [];

  for (let j = 0; j < casesNumbers.length; j++) {
    console.log(casesNumbers[j].join(' '));

    let sum = (await readLine())
      .split(' ')
      .map(Number)
      .reduce((a, b) => a + b);

    reminders.push(sum);
  }
  debugger;
  let sol = crt(reminders, numbers);
  console.log(sol);
}

function crt(reminders, numbers) {
  let product = numbers.reduce((a, b) => a * b, 1);
  let partialProduct = numbers.map(n => product / n);
  let inverse = numbers.map((n, i) => computeInverse(partialProduct[i], n));

  let sum = 0;
  for (let i = 0; i < numbers.length; i++) {
    sum += partialProduct[i] * inverse[i] * reminders[i];
  }

  return sum % product;
}

function computeInverse(a, b) {
  let t = 0;
  let q = 0;
  let x = 0;
  let m = b;
  let y = 1;

  if (b == 1) {
    return 0;
  }

  // Apply extended Euclid Algorithm
  while (a > 1) {
    // q is quotient
    q = Math.floor(a / b);
    t = b;

    // now proceed same as Euclid's algorithm
    b = a % b;
    a = t;
    t = x;
    x = y - q * x;
    y = t;
  }

  // Make x1 positive
  if (y < 0) {
    y += m;
  }

  return y;
}
