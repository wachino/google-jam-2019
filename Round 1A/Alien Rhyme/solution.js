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

function solution() {
  const t = Number(readLine());
  for (let i = 0; i < t; i++) {
    let N = Number(readLine());
    var trie = {};
    for (let j = 0; j < N; j++) {
      insertToTree(
        trie,
        readLine()
          .split('')
          .reverse()
          .join('')
      );
    }
    const r = Object.values(trie).reduce((a, c) => a + minimumUnpaired(c), 0);

    console.log(`Case #${i + 1}: ${N - r}`);
  }
}

function minimumUnpaired(root) {
  if (root === 'leaf') {
    return 1;
  }
  let r = Object.values(root).reduce((a, c) => a + minimumUnpaired(c), 0);
  if (r >= 2) {
    r -= 2;
  }
  return r;
}

function insertToTree(root, word) {
  if (word.length === 0) {
    root.leaf = 'leaf';
    return;
  }
  const c = word[0];
  if (!root[c]) {
    root[c] = {};
  }
  insertToTree(root[c], word.slice(1));
}
