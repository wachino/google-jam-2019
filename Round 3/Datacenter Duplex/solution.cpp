#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <vector>
#include <functional>
#include <string>

using namespace std;
struct subset
{
  int parent;
  int rank;
};

int find(struct subset components[], int i)
{
  if (components[i].parent != i)
    components[i].parent = find(components, components[i].parent);

  return components[i].parent;
}

void setUnion(struct subset components[], int x, int y)
{
  int xroot = find(components, x);
  int yroot = find(components, y);

  if (components[xroot].rank < components[yroot].rank)
  {
    components[xroot].parent = yroot;
  }
  else if (components[xroot].rank > components[yroot].rank)
  {
    components[yroot].parent = xroot;
  }

  else
  {
    components[yroot].parent = xroot;
    components[xroot].rank++;
  }
}

int main()
{
  int T, R, C;
  int dataCenter[100][100];
  int diagonals[100][100];
  subset connectedComponents[10000];

  bool isPossible;
  string line;
  cin >> T;
  for (int t = 0; t < T; t++)
  {
    cin >> R >> C;
    getline(cin, line);
    for (int i = 0; i < R; i++)
    {
      getline(cin, line);
      for (int j = 0; j < C; j++)
      {
        diagonals[i][j] = 0;
        if (line[j] == 'A')
        {
          dataCenter[i][j] = -1;
        }
        else
        {
          dataCenter[i][j] = 1;
        }
        connectedComponents[i * C + j] = {.parent = i * C + j, .rank = 0};
      }
    }
    for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
      {
        if (i > 0 && dataCenter[i][j] == dataCenter[i - 1][j])
        {
          setUnion(connectedComponents, i * C + j, (i - 1) * C + j);
        }
        if (j > 0 && dataCenter[i][j] == dataCenter[i][j - 1])
        {
          setUnion(connectedComponents, i * C + j, i * C + j - 1);
        }
      }
    }
    for (int i = 0; i < R - 1; i++)
    {
      for (int j = 0; j < C - 1; j++)
      {
        if (diagonals[i][j] == 0)
        {
          if (dataCenter[i][j] == dataCenter[i + 1][j + 1] &&
              find(connectedComponents, i * C + j) != find(connectedComponents, (i + 1) * C + j + 1))
          {
            setUnion(connectedComponents, i * C + j, (i + 1) * C + j + 1);
            diagonals[i][j] = -1;
          }
          else if (dataCenter[i + 1][j] == dataCenter[i][j + 1] &&
                   find(connectedComponents, (i + 1) * C + j) != find(connectedComponents, i * C + j + 1))
          {
            setUnion(connectedComponents, (i + 1) * C + j, i * C + j + 1);
            diagonals[i][j] = 1;
          }
        }
      }
    }
    int aParent = -1;
    int bParent = -1;
    isPossible = true;
    for (int i = 0; i < R; i++)
    {
      if (!isPossible)
      {
        break;
      }
      for (int j = 0; j < C; j++)
      {
        if (dataCenter[i][j] == -1)
        {
          int tmpA = find(connectedComponents, i * C + j);
          if (aParent == -1)
          {
            aParent = tmpA;
          }
          else if (aParent != tmpA)
          {
            isPossible = false;
            break;
          }
        }
        else if (dataCenter[i][j] == 1)
        {
          int tmpB = find(connectedComponents, i * C + j);
          if (bParent == -1)
          {
            bParent = tmpB;
          }
          else if (bParent != tmpB)
          {
            isPossible = false;
            break;
          }
        }
      }
    }
    cout << "Case #" << t + 1 << ": " << (isPossible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    if (isPossible)
    {
      for (int i = 0; i < R - 1; i++)
      {
        for (int j = 0; j < C - 1; j++)
        {
          switch (diagonals[i][j])
          {
          case 0:
            cout << '.';
            break;
          case -1:
            cout << '\\';
            break;
          case 1:
            cout << '/';
            break;
          }
        }
        cout << endl;
      }
    }
  }
  return 0;
}