//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu5687.cpp
 *  Date : 2016年5月21日 下午11:53:14
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

struct node {
  map<char, int> nxt;
  int par;
  int cnt;
  char ele;
};

vector<node> f;

int create(int par, char ele) {
  node m; m.par = par; m.cnt = 0; m.ele = ele;
  return f.push_back(m), f.size() - 1;
}

void insert(int u, char* s) {
  if (!*s) { ++f[u].cnt; return; }
  int& v = f[u].nxt[*s];
  if (!v) v = create(u, *s);
  insert(v, s + 1);
}

void clear(int u) {
  do {
    f[f[u].par].nxt.erase(f[u].ele), u = f[u].par;
  } while (u && !f[u].cnt && f[u].nxt.empty());
}

void erase(int u, char* s) {
  if (!*s) { clear(u); return; }
  if (f[u].nxt.count(*s)) erase(f[u].nxt[*s], s + 1);
}

bool find(int u, char *s) {
  if (!*s) return true;
  if (f[u].nxt.count(*s)) return find(f[u].nxt[*s], s + 1);
  return false;
}

char s[50];

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(int n; cin >> n; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    f.clear(); int root = create(-1, 0);
    while (n--) {
      string op; cin >> op >> s;
      if (op == "insert") insert(root, s);
      else if (op == "delete") erase(root, s);
      else if (op == "search") cout << (find(root, s) ? "Yes" : "No") << endl;
      else assert(false);
    }
  }
  return 0;
}
