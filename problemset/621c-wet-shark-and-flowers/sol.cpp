#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <tuple>
#include <valarray>
#include <cassert>
#include <cstring>
#include <typeinfo>
#include <functional>
#include <memory>
#include <regex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using sstrm = stringstream;
using ld = long double;

#define ZERO(a) std::memset((a), 0, sizeof(a))
#define FILL1D(a, v) std::fill_n(a, sizeof(a) / sizeof(a[0]), v)
#define FILL2D(a, v) std::fill_n(&a[0][0], sizeof(a) / sizeof(a[0][0]), v)
#define FILL3D(a, v) std::fill_n(&a[0][0][0], sizeof(a) / sizeof(a[0][0][0]), v)
#define FILL4D(a, v) std::fill_n(&a[0][0][0][0], sizeof(a) / sizeof(a[0][0][0][0]), v)
#define COPY1D(a, b) std::copy_n(a, sizeof(a) / sizeof(a[0]), b)
#define COPY2D(a, b) std::copy_n(&a[0][0], sizeof(a) / sizeof(a[0][0]), &b[0][0])
#define COPY3D(a, b) std::copy_n(&a[0][0][0], sizeof(a) / sizeof(a[0][0][0]), &b[0][0][0])
#define COPY4D(a, b) std::copy_n(&a[0][0][0][0], sizeof(a) / sizeof(a[0][0][0][0]), &b[0][0][0][0])
#define FOR(k, a, b) for (decltype(a) k = (a); k <= (b); ++k)
#define RFOR(k, a, b) for (decltype(a) k = (a); (b) <= k; --k)
#define REP(k, a) for (int k = 0; k < (a); ++k)
#define SQR(x) ((x) * (x))
#define PW(x) (1ll << (x))
#define BCNT(x) __builtin_popcountll(x)
#define LZC(x) ((x) == 0 ? sizeof(x) * 8 : __builtin_clzll(x))
#define RZC(x) ((x) == 0 ? sizeof(x) * 8 : __builtin_ctzll(x))
#define ALL(c) (c).begin(),(c).end()
#define HAS(c, x) ((c).find(x) != (c).end())
#define CHAS(c, x) (find(ALL(c), x) != (c).end())

template<typename S, typename T> inline void chmin(S& a, T b) { if (b < a) a = b; }
template<typename S, typename T> inline void chmax(S& a, T b) { if (a < b) a = b; }

// debug print, noop when ONLINE_JUDGE is passed
// usage: debug << foo; ()
struct debug_t {};
template<typename T_>
debug_t& operator<<(debug_t& out_, T_& t_)
{
  (void) t_;
#ifndef ONLINE_JUDGE
  cerr << t_;
#endif
  return out_;
}
debug_t debug;

int main()
{
  iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(17);
  cout << fixed;

  u32 n, p;
  cin >> n >> p;
  vector<ld> v(n);
  REP(i, n) {
    u32 l, r;
    cin >> l >> r;
    u32 lk = l % p == 0 ? l / p : l / p + 1;
    u32 rk = r / p;
    if (lk > rk) continue;
    ld prob = ld(rk - lk + 1) / (r - l + 1);
    v[i] = prob;
  }

  ld ev = 0;
  REP(i, n) {
    REP(k, 2) {
      int j1 = (i + k) % n;
      int j2 = (i + k + 1) % n;
      ev += (1 - (1 - v[j1]) * (1 - v[j2])) * 1000;
    }
  }
  cout << ev << "\n";
}
