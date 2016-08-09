//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6489.cpp
 *  Date : 2016年7月17日 上午8:50:00
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";
int hack[256];

std::string base64_decode(string a) {
  string res = "";
  auto it = a.begin();
  assert(a.size() % 4 == 0);
  rep(k, 0, (int)a.size() / 4) {
    long long r = 0;
    rep(i, 0, 4) r = (r << 6) + hack[(int)*it++];
    int c = r & 0xff; r >>= 8;
    int b = r & 0xff; r >>= 8;
    int a = r & 0xff; r >>= 8;
    res = res + char(a) + char(b) + char(c);
  }
  assert(it == a.end());
  return res;
}

//@ Main Function
int main() {
  for (int i = 0; i < (int)base64_chars.size(); ++i) hack[(int)base64_chars[i]] = i;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  string tmp;
  for(std::cin >> _, getline(cin, tmp); _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    string in; getline(cin, in);
    int n; cin >> n; getline(cin, tmp);
    string s; getline(cin, s);

    in = base64_decode(in);

    int d = 0;
    for (auto &ch : in) {
      assert(islower(ch));
      assert(islower(s[d]));
      int a = ch - 'a';
      int b = s[d] - 'a' + 1;
      ch = (a + 26 - b) % 26 + 'a';
      d = (d + 1) % s.size();
    }

    vector<vector<int>> v(n);
    rep(i, 0, (int)in.size()) v[i % n].push_back(i);
    vector<int> ans;
    for (auto &u : v) for (auto ui : u) ans.push_back(ui);
    string out(in);
    rep(i, 0, (int)in.size()) out[ans[i]] = in[i];
    cout << out << endl;

//    int m = in.size() / n, p = in.size() % n;
//    if (p) {
//      string ss = ""; int l = 0;
//      rep(i, 0, n) {
//        if (p)
//          ss += in.substr(l, m + 1), l += m + 1, --p;
//        else
//          ss += in.substr(l, m) + ' ', l += m;
//      }
//      assert(l == (int)in.size());
//      in = ss, m = in.size() / n;
//    }
//    assert(in.size() % n == 0);
//    rep(i, 0, m)
//      for (int j = i; j < (int)in.size(); j += m) if (in[j] != ' ') cout << in[j];
  }
  return 0;
}
