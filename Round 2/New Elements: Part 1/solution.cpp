#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

template <typename Number>
Number GCD(Number u, Number v)
{
  while (v != 0)
  {
    Number r = u % v;
    u = v;
    v = r;
  }
  return u;
}

int main()
{
  int T, N, g, ra, rb;
  pair<int, int> *molecules;
  set<pair<int, int>> inflexionPoints;
  cin >> T;
  for (int t = 0; t < T; t++)
  {
    inflexionPoints.clear();
    cin >> N;
    molecules = new pair<int, int>[N];
    for (int i = 0; i < N; i++)
    {
      cin >> molecules[i].first >> molecules[i].second;
    }

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (molecules[i].first != molecules[j].first && molecules[i].second != molecules[j].second)
        {
          ra = (molecules[i].first - molecules[j].first);
          rb = (molecules[i].second - molecules[j].second);
          if ((ra > 0 && rb < 0) || (ra < 0 && rb > 0))
          {
            ra = abs(ra);
            rb = abs(rb);
            g = GCD(ra, rb);
            ra /= g;
            rb /= g;
            inflexionPoints.insert(make_pair(ra, rb));
          }
        }
      }
    }

    cout << "Case #" << t + 1 << ": " << inflexionPoints.size() + 1 << endl;

    delete[] molecules;
  }
  return 0;
}