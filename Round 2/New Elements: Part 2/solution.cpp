#include <iostream>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

struct Fraction
{
  long long a;
  long long b;
  Fraction(long long num, long long den) : a(num), b(den) {}
};

Fraction aprox(Fraction lowerDelta, Fraction upperDelta, Fraction lowerLimit, Fraction upperLimit)
{
  Fraction mid(lowerLimit.a + upperLimit.a, lowerLimit.b + upperLimit.b);
  if (lowerDelta.a * mid.b >= mid.a * lowerDelta.b)
  {
    Fraction inc(upperLimit.a, upperLimit.b);
    Fraction ret(lowerLimit.a, lowerLimit.b);
    while (lowerDelta.a * (inc.b + ret.b) >= lowerDelta.b * (inc.a + ret.a))
    {
      ret.a += inc.a;
      ret.b += inc.b;
      inc.a += inc.a;
      inc.b += inc.b;
    }
    return aprox(lowerDelta, upperDelta, ret, upperLimit);
  }
  else if (upperDelta.b * mid.a >= mid.b * upperDelta.a)
  {
    Fraction inc(lowerLimit.a, lowerLimit.b);
    Fraction ret(upperLimit.a, upperLimit.b);
    while ((inc.a + ret.a) * upperDelta.b >= upperDelta.a * (inc.b + ret.b))
    {
      ret.a += inc.a;
      ret.b += inc.b;
      inc.a += inc.a;
      inc.b += inc.b;
    }
    return aprox(lowerDelta, upperDelta, lowerLimit, ret);
  }
  return mid;
}

long long GCD(long long u, long long v)
{
  while (v != 0LL)
  {
    long long r = u % v;
    u = v;
    v = r;
  }
  return u;
}

int main()
{
  int T, N;
  pair<long long, long long> *molecules;
  cin >> T;
  for (int t = 0; t < T; t++)
  {
    cin >> N;
    molecules = new pair<long long, long long>[N];
    for (int i = 0; i < N; i++)
    {
      cin >> molecules[i].first >> molecules[i].second;
    }
    Fraction lowerDelta(0LL, 1LL);
    Fraction upperDelta(1LL, 0);
    long long deltaJ;
    long long deltaC;
    long long g;
    bool imp = false;
    for (int i = 0; i < N - 1; i++)
    {
      deltaC = molecules[i + 1].first - molecules[i].first;
      deltaJ = molecules[i + 1].second - molecules[i].second;
      if (deltaJ <= 0 && deltaC <= 0)
      {
        imp = true;
      }

      if (deltaC < 0 && deltaJ > 0)
      {
        deltaC = abs(deltaC);
        deltaJ = abs(deltaJ);
        if (deltaC * lowerDelta.b > lowerDelta.a * deltaJ)
        {
          g = GCD(deltaC, deltaJ);
          lowerDelta.a = deltaC / g;
          lowerDelta.b = deltaJ / g;
        }
      }
      else if (deltaC > 0 && deltaJ < 0)
      {
        deltaC = abs(deltaC);
        deltaJ = abs(deltaJ);
        if (upperDelta.a * deltaJ > deltaC * upperDelta.b)
        {
          g = GCD(deltaC, deltaJ);
          upperDelta.a = deltaC / g;
          upperDelta.b = deltaJ / g;
        }
      }
    }
    if (lowerDelta.a * upperDelta.b >= upperDelta.a * lowerDelta.b)
    {
      imp = true;
    }
    if (imp)
    {
      cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
    }
    else
    {
      Fraction sol = aprox(lowerDelta, upperDelta, Fraction(0, 1), Fraction(1, 0));
      cout << "Case #" << t + 1 << ": " << sol.b << " " << sol.a << endl;
    }
    delete[] molecules;
  }
  return 0;
}