const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

async function ask(q = '') {
  return new Promise(solve => {
    rl.question(q, response => solve(response));
  });
}

rl.question('', async firstLine => {
  const t = Number(firstLine);
  for (let i = 0; i < t; i++) {
    let caseInfo = await ask();
    let [N, B, F] = caseInfo
      .trim()
      .split(' ')
      .map(Number);

    let working = Array(N).fill(true);
    searchFail(0, N, B);

    let veredict = await ask();
    rl.close();
  }

  function getString(left, right, k) {
    const midPoint = Math.floor((right + left + 1) / 2);
    const half = Math.floor((right - left + 1) / 2);
    console.log({ left, right, midPoint, k });
    if (k === 0) {
      return (q = '1'.repeat(half) + '0'.repeat(right - left - half));
    }
    return getString(left, midPoint, k - 1) + getString(midPoint, right, k - 1);
  }
  function searchFail(left, right, nFails, k) {
    const quest = getString(left, right, k);

    const q = '1'.repeat(mid) + '0'.repeat(right - left - mid);
  }
});
