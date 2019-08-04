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
debug_t& operator<<(debug_t& out_, T_&& t_)
{
  (void) t_;
#ifndef ONLINE_JUDGE
  cerr << std::forward<T_>(t_);
#endif
  return out_;
}
debug_t debug;

tuple<i64, i64, i64> gcd(i64 a, i64 b)
{
    if (a == 0) return make_tuple(b, 0, 1);
    i64 g, x, y;
    tie(g, x, y) = gcd(b % a, a);
    auto tmp = x;
    x = y - (b / a) * x;
    y = tmp;
    return make_tuple(g, x, y);
}

i64 modInv(i64 x, i64 m)
{
    i64 g, a, b;
    tie(g, a, b) = gcd(x, m);
    assert(1 == g);
    if (a < 0) a += m;
    assert(0 < a);
    assert(a < m);
    return a;
}

constexpr i64 mod_value = 1e9 + 7;

i64 mod(i64 x)
{
  auto res = x % mod_value;
  if (res < 0) res += mod_value;
  return res;
}

i64 inv(i64 x)
{
  return modInv(x, mod_value);
}

int main()
{
  iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(17);
  cout << fixed;

  int n, m;
  cin >> n >> m;

  vector<int> s1(n), s2(n);
  REP(i, n) cin >> s1[i];
  REP(i, n) cin >> s2[i];

  const i64 im = inv(m);

  debug << "im = " << im << "\n";
  debug << "im * m = " << mod(im * m) << "\n";
  debug << "(26 - 11) / 26 = " << mod((26 - 10) * im) << "\n";

  i64 res = 0;
  i64 p = 1;
  REP(i, n) {
    int x = s1[i];
    int y = s2[i];
    if (x != 0 and y != 0) {
      debug << "here 1\n";
      if (x == y) continue;
      if (x > y) {
        res = mod(res + p);
      }
      break;
    }
    if (x == 0 and y == 0) {
      debug << "here 2\n";
      res = mod(res + mod(p * mod(mod(1 - im) * inv(2))));
    }
    else if (x == 0) {
      debug << "here 3\n";
      res = mod(res + mod(p * mod((m - y) * im)));
    }
    else if (y == 0) {
      debug << "here 4\n";
      res = mod(res + mod(p * mod((x - 1) * im)));
    }
    p = mod(p * im);
  }
  cout << res << "\n";
}
