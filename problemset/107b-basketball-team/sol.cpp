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

ld dp[101][101] = {};

int main()
{
  iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(17);
  cout << fixed;

  int n, m, h;
  cin >> n >> m >> h;
  h -= 1;
  vector<int> s;
  REP(i, m) {
    int si;
    cin >> si;
    s.push_back(si);
  }
  int total = std::accumulate(s.begin(), s.end(), 0);
  if (total < n) {
    cout << "-1\n";
    return 0;
  }

  int friends = s[h] - 1;
  int others = total - friends - 1;
  int team = n - 1;

  debug << "friends: " << friends << "\n"
        << "others: " << others << "\n"
        << "team size: " << team << "\n";

  dp[0][0] = 1;
  FOR(i, 1, friends) {
    int friends_rem = friends - i + 1;
    int all_rem = others + friends_rem;
    dp[i][0] = dp[i - 1][0] * friends_rem / all_rem;
  }

  FOR(j, 1, team) {
    if (j > others) break;
    int other_rem = others - j + 1;
    int all_rem = other_rem + friends;
    dp[0][j] = dp[0][j - 1] * other_rem / all_rem;
  }

  cerr << setprecision(2);
  REP(i, team) {
    REP(j, team) {
      debug << "dp[" << i << "][" << j << "]=" << dp[i][j] << " ";
    }
    debug << "\n";
  }
  debug << "\n\n";

  FOR(i, 1, friends) {
    FOR(j, 1, team) {
      if (j > others) break;
      int all_prev = friends - i + others - j + 1;
      debug << "i: " << i << ", j: " << j << "\n";
      debug << "all_prev: " << all_prev << "\n";
      dp[i][j] =
        dp[i - 1][j] * (friends - i + 1) / all_prev +
        dp[i][j - 1] * (others - j + 1) / all_prev;
    }
  }

  debug << "\n\n";
  REP(i, team) {
    REP(j, team) {
      debug << "dp[" << i << "][" << j << "]=" << dp[i][j] << " ";
    }
    debug << "\n";
  }

  ld res = 0;
  REP(i, 101) REP(j, 101) if (i > 0 and i + j == team) res += dp[i][j];

  cout << res << "\n";
}
