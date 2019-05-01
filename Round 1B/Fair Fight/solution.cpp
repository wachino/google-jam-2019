#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void pushDown(int *lazyTree, int *segmentTree, int node)
{
  if (lazyTree[node])
  {
    int leftChildNode = (node << 1) | 1;
    int rightChildNode = (node + 1) << 1;

    segmentTree[leftChildNode] += lazyTree[node];
    segmentTree[rightChildNode] += lazyTree[node];
    lazyTree[leftChildNode] += lazyTree[node];
    lazyTree[rightChildNode] += lazyTree[node];
    lazyTree[node] = 0;
  }
}

void pushUp(int *segmentTree, int node)
{
  int leftChildNode = (node << 1) | 1;
  int rightChildNode = (node + 1) << 1;

  segmentTree[node] = max(segmentTree[leftChildNode], segmentTree[rightChildNode]);
}

void update(int *lazyTree, int *segmentTree, int addValue, int start, int end, int left, int right, int node)
{
  if (left <= start && end <= right)
  {
    segmentTree[node] += addValue;
    lazyTree[node] += addValue;
    return;
  }
  pushDown(lazyTree, segmentTree, node);
  int mid = (start + end) >> 1;
  int leftChildNode = (node << 1) | 1;
  int rightChildNode = (node + 1) << 1;
  if (left <= mid)
    update(lazyTree, segmentTree, addValue, start, mid, left, right, leftChildNode);
  if (right > mid)
    update(lazyTree, segmentTree, addValue, mid + 1, end, left, right, rightChildNode);

  pushUp(segmentTree, node);
}

int query(int *lazyTree, int *segmentTree, int start, int end, int left, int right, int node)
{
  if (right < start || end < left)
  {
    return -1;
  }
  if (left <= start && end <= right)
  {
    return segmentTree[node];
  }
  int mid = (start + end) >> 1;
  pushDown(lazyTree, segmentTree, node);
  int leftChildNode = (node << 1) | 1;
  int rightChildNode = (node + 1) << 1;
  return max(query(lazyTree, segmentTree, start, mid, left, right, leftChildNode), query(lazyTree, segmentTree, mid + 1, end, left, right, rightChildNode));
}

void buildSegmentTree(int *segmentTree, int *input, int start, int end, int node)
{
  if (start == end)
  {
    segmentTree[node] = input[start];
  }
  else
  {
    int mid = (start + end) >> 1;
    int leftChildNode = (node << 1) | 1;
    int rightChildNode = (node + 1) << 1;
    buildSegmentTree(segmentTree, input, start, mid, leftChildNode);
    buildSegmentTree(segmentTree, input, mid + 1, end, rightChildNode);
    segmentTree[node] = max(segmentTree[leftChildNode], segmentTree[rightChildNode]);
  }
}

long long searchLeftLessThan(int *lazyTree, int *segmentTree, int start, int end, int left, int right, int node, int maxValue)
{
  int Q = query(lazyTree, segmentTree, start, end, left, right, node);
  if (Q <= maxValue)
  {
    return (long long int)left;
  }
  int nLeft = left;
  int nRight = right;
  while (nLeft <= nRight)
  {
    int mid = (nLeft + nRight) >> 1;
    int v = query(lazyTree, segmentTree, start, end, mid, right, node);
    if (v > maxValue)
    {
      nLeft = mid + 1;
    }
    else
    {
      nRight = mid - 1;
    }
  }
  return (long long int)nLeft;
}

long long searchRightLessThan(int *lazyTree, int *segmentTree, int start, int end, int left, int right, int node, int maxValue)
{
  int Q = query(lazyTree, segmentTree, start, end, left, right, node);
  if (Q <= maxValue)
  {
    return (long long)right;
  }
  int nLeft = left;
  int nRight = right;
  while (nLeft <= nRight)
  {
    int mid = (nLeft + nRight) >> 1;
    int v = query(lazyTree, segmentTree, start, end, left, mid, node);
    if (v > maxValue)
    {
      nRight = mid - 1;
    }
    else
    {
      nLeft = mid + 1;
    }
  }
  return (long long)nRight;
}

int main()
{
  int T, N, K;
  char dir;
  int *charlesSkills;
  int *charlesTree;
  int *charlesLazyTree;
  int *delilaSkills;
  int *delilaTree;
  int *delilaLazyTree;

  pair<int, int> *persons;
  cin >> T;
  for (int t = 0; t < T; t++)
  {
    cin >> N >> K;
    charlesSkills = new int[N];
    delilaSkills = new int[N];
    charlesTree = new int[4 * (N + 1)];
    charlesLazyTree = new int[4 * (N + 1)];
    delilaTree = new int[4 * (N + 1)];
    delilaLazyTree = new int[4 * (N + 1)];

    for (int i = 0; i < 4 * (N + 1); i++)
    {
      charlesTree[i] = 0;
      charlesLazyTree[i] = 0;
      delilaTree[i] = 0;
      delilaLazyTree[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
      cin >> charlesSkills[i];
      charlesSkills[i]++;
    }
    for (int i = 0; i < N; i++)
    {
      cin >> delilaSkills[i];
      delilaSkills[i]++;
    }
    buildSegmentTree(charlesTree, charlesSkills, 0, N - 1, 0);
    buildSegmentTree(delilaTree, delilaSkills, 0, N - 1, 0);
    long long sol = 0;
    int currCharles = 0;

    for (long long int i = 0; i < N; i++)
    {
      currCharles = charlesSkills[i];
      int lC = i;
      if (i > 0)
      {
        lC = min(i, searchLeftLessThan(charlesLazyTree, charlesTree, 0, N - 1, 0, i - 1, 0, currCharles - 1));
      }
      int rC = searchRightLessThan(charlesLazyTree, charlesTree, 0, N - 1, i, N - 1, 0, currCharles);
      int lDEnough = searchLeftLessThan(delilaLazyTree, delilaTree, 0, N - 1, 0, i, 0, currCharles + K);
      int rDEnough = searchRightLessThan(delilaLazyTree, delilaTree, 0, N - 1, i, N - 1, 0, currCharles + K);
      int lDTooGood = searchLeftLessThan(delilaLazyTree, delilaTree, 0, N - 1, 0, i, 0, currCharles - K - 1);
      int rDTooGood = searchRightLessThan(delilaLazyTree, delilaTree, 0, N - 1, i, N - 1, 0, currCharles - K - 1);

      int p1p2L = max(lC, lDEnough);
      int p1p2R = min(rC, rDEnough);
      int p1p3L = max(lC, lDTooGood);
      int p1p3R = min(rC, rDTooGood);
      sol += (long long)((long long)((i - p1p2L + 1LL) * (p1p2R - i + 1LL)) - (long long int)((i - p1p3L + 1LL) * (p1p3R - i + 1LL)));
    }

    cout << "Case #" << t + 1 << ": " << sol << endl;

    delete[] charlesSkills;
    delete[] delilaSkills;
    delete[] charlesTree;
    delete[] charlesLazyTree;
    delete[] delilaTree;
    delete[] delilaLazyTree;
  }
  return 0;
}