#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>

using namespace std;
typedef long long ll;
static const double EPS = 1e-8;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define DEC(i, s) for (int i = (s); i >= 0; i--)

#define SIZE(v) (int)((v).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define FIND(m, w) ((m).find(w) != (m).end())

#include <complex>
#include <vector>

using namespace std;
typedef complex<ll> Point;

static const double INF = 1e+10;

struct Line : public vector<Point> {
  Line() {;}
  Line(Point a, Point b) { push_back(a); push_back(b); }
};

namespace std {
  bool operator<(const Point &lhs, const Point &rhs) {
    return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();
  }
}

inline double cross(const Point &a, const Point &b) {
  return imag(conj(a) * b);
}

inline double dot(const Point &a, const Point &b) {
  return real(conj(a) * b);
}

inline int ccw(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) { return 1; }
  if (cross(b, c) < 0) { return -1; }
  //if (dot(b, c) < 0) { return 2; }
  //if (norm(b) < norm(c)) { return -2; }
  return 0;
}

bool intersectSP(const Line &s, const Point &p) {
  if (min(s[0].real(), s[1].real()) > p.real()) { return false; }
  if (max(s[0].real(), s[1].real()) < p.real()) { return false; }
  if (min(s[0].imag(), s[1].imag()) > p.imag()) { return false; }
  if (max(s[0].imag(), s[1].imag()) < p.imag()) { return false; }
  return ccw(p, s[0], s[1]) == 0;
}

bool intersectPP(const Point &a, const Point &b) {
  return a.real() == b.real() && a.imag() == b.imag();
}

bool endIntersect(Line &l1, Line &l2) {
  if (intersectPP(l1[0], l2[0])) {
    return true;
  } else if (intersectPP(l1[0], l2[1])) {
    swap(l2[0], l2[1]);
    return true;
  } else if (intersectPP(l1[1], l2[0])) {
    swap(l1[0], l1[1]);
    return true;
  } else if (intersectPP(l1[1], l2[1])) {
    swap(l1[0], l1[1]);
    swap(l2[0], l2[1]);
    return true;
  }
  return false;
}

Line line[3];

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    REP(i, 3) {
      int a, b, c, d;
      scanf("%d %d %d %d", &a, &b, &c, &d);
      line[i] = Line(Point(a, b), Point(c, d));
    }
    {
      if (endIntersect(line[0], line[1])) {
      } else if (endIntersect(line[1], line[2])) {
        swap(line[2], line[0]);
      } else if (endIntersect(line[2], line[0])) {
        swap(line[2], line[1]);
      } else {
        goto no;
      }
      if (intersectSP(line[0], line[2][0]) && intersectSP(line[1], line[2][1])) {
      } else if (intersectSP(line[0], line[2][1]) && intersectSP(line[1], line[2][0])) {
        swap(line[2][0], line[2][1]);
      } else {
        goto no;
      }
      if (norm(line[0][1] - line[1][1]) > norm(line[0][0] - line[0][1]) + norm(line[1][1] - line[1][0])) { goto no; }
      if (intersectSP(line[0], line[1][1]) || intersectSP(line[1], line[0][1])) { goto no; }
      ll lup = norm(line[0][0] - line[2][0]);
      ll ldown = norm(line[0][1] - line[2][0]);
      ll rup = norm(line[1][0] - line[2][1]);
      ll rdown = norm(line[1][1] - line[2][1]);
      //cout << ldown << " " << lup << endl;
      if (ldown < lup) { swap(ldown, lup); }
      if (rdown < rup) { swap(rdown, rup); }
      if (lup * 16 < ldown) { goto no; }
      if (rup * 16 < rdown) { goto no; }
      puts("YES");
      goto next;
    }
no:;
   puts("NO");
next:;
  }
}

