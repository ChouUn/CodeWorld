//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju3930.cpp
 *  Date : 2016年4月12日 上午12:59:25
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

string str;

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _, getline(cin, str); _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    string a = "", b = ""; int d = 0;
    getline(cin, str); str += '!';
    for(auto &ch : str) {
      int sign = 0;
      switch (ch) {
        case '+': case '-': case '*': case '/': sign = 1; break;
        case '(': case ')': sign = 2; break;
        case ' ': case '\t': sign = 3; break;
        case '!': sign = 4; break;
        case 'd': sign = 5; break;
      }
      if (sign && sign != 5) {
        if (d) {
          int x = (a != "" ? atoi(a.data()) : 1);
          if (x != 1) cout << '(';
          for (int i = 0, flag = 0; i < x; ++i) {
            if (flag) cout << " + ";
            cout << "[d" << b << ']', flag = true;
          }
          if (x != 1) cout << ')';
          a = b = "", d = 0;
        }
        else
          cout << a, a = "";
      }
      if (sign == 1) { cout << ' ' << ch << ' '; continue; }
      if (sign == 2) { cout << ch; continue; }
      if (sign == 3) continue;
      if (sign == 4) break;
      if (sign == 5) { d = 1; continue; }
      (d ? b : a) += ch;
    }
    cout << " = [Result]"<< endl;
  }
  return 0;
}
