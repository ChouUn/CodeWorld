//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu3652.cpp
 *  Date : 2015年11月28日 下午5:59:31
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 11
int dp[maxn][13][3];
int num[maxn];

int solve(int bit, int mod, int status, bool border) {
  if(!border && ~dp[bit][mod][status]) return dp[bit][mod][status];
  if(bit == 0) return mod == 0 && status == 2;
  int res = 0;
  for(int i = 0; i <= (border ? num[bit] : 9); ++i)
    res += solve(bit - 1, (mod * 10 + i) % 13,
        status == 2 || (status == 1 && i == 3) ? 2 : (i == 1), border && (i == num[bit]));
  if(!border) dp[bit][mod][status] = res;
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int m; cin >> m; --_, ++__) {
    //std::cout << "Case #" << __ <<": ";
    memset(dp, 0xff, sizeof dp);
    int bit = 0;
    for (int n = m; n; n /= 10) num[++bit] = n % 10;
    cout << solve(bit, 0, 0, true) << endl;
  }
  return 0;
}
