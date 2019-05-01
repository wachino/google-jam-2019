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

int search(int *lazyTree, int *segmentTree, int start, int end, int value, int node)
{
  if (start == end)
  {
    return start;
  }

  int mid = (start + end) >> 1;
  pushDown(lazyTree, segmentTree, node);
  int leftChildNode = (node << 1) | 1;
  int rightChildNode = (node + 1) << 1;
  int lQuery = query(lazyTree, segmentTree, start, mid, start, mid, leftChildNode);
  int rQuery = query(lazyTree, segmentTree, mid + 1, end, mid + 1, end, leftChildNode);
  if (lQuery == value)
  {
    return search(lazyTree, segmentTree, start, mid, value, leftChildNode);
  }
  return search(lazyTree, segmentTree, mid + 1, end, value, rightChildNode);
}

void buildSegmentTree(int *segmentTree, int start, int end, int node)
{
  if (start == end)
  {
    segmentTree[node] = 0;
  }
  else
  {
    int mid = (start + end) >> 1;
    int leftChildNode = (node << 1) | 1;
    int rightChildNode = (node + 1) << 1;
    buildSegmentTree(segmentTree, start, mid, leftChildNode);
    buildSegmentTree(segmentTree, mid + 1, end, rightChildNode);
    segmentTree[node] = max(segmentTree[leftChildNode], segmentTree[rightChildNode]);
  }
}

int main()
{
  int T, P, Q, x, y;
  char dir;
  int *hStreets;
  int *lazyHStreets;
  int *vStreets;
  int *lazyVStreets;
  pair<int, int> *persons;
  cin >> T;
  for (int t = 0; t < T; t++)
  {
    cin >> P >> Q;
    hStreets = new int[4 * (Q + 1)];
    lazyHStreets = new int[4 * (Q + 1)];
    vStreets = new int[4 * (Q + 1)];
    lazyVStreets = new int[4 * (Q + 1)];

    for (int i = 0; i < 4 * (Q + 1); i++)
    {
      hStreets[i] = 0;
      lazyHStreets[i] = 0;
      vStreets[i] = 0;
      lazyVStreets[i] = 0;
    }
    buildSegmentTree(hStreets, 0, Q, 0);
    buildSegmentTree(vStreets, 0, Q, 0);
    for (int i = 0; i < P; i++)
    {
      cin >> x >> y >> dir;
      if (dir == 'N')
      {
        update(lazyHStreets, hStreets, 1, 0, Q, y + 1, Q, 0);
      }
      else if (dir == 'S')
      {
        update(lazyHStreets, hStreets, 1, 0, Q, 0, y - 1, 0);
      }
      else if (dir == 'W')
      {
        update(lazyVStreets, vStreets, 1, 0, Q, 0, x - 1, 0);
      }
      else if (dir == 'E')
      {
        update(lazyVStreets, vStreets, 1, 0, Q, x + 1, Q, 0);
      }
    }
    int maxH = query(lazyHStreets, hStreets, 0, Q, 0, Q, 0);
    int solY = search(lazyHStreets, hStreets, 0, Q, maxH, 0);
    int maxV = query(lazyVStreets, vStreets, 0, Q, 0, Q, 0);
    int solX = search(lazyVStreets, vStreets, 0, Q, maxV, 0);

    cout << "Case #" << t + 1 << ": " << solX << " " << solY << endl;

    delete[] hStreets;
    delete[] vStreets;
    delete[] lazyHStreets;
    delete[] lazyVStreets;
  }
  return 0;
}