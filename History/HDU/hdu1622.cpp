//@ Including Header
#include <csl_std.h>

/**
 *  Name : hdu1622.cpp
 *  Date : 2016年4月26日 下午2:21:07
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define N 300
int n;
char s[N];

struct node {
  uint d; node* ch[2];
  node() : d(0xDEADBEEF) { ch[0] = ch[1] = nullptr; }
};
node v[N]; int ve, dirty;

void add_node() {
  node* m = v;
  for (int i = 0; s[i] != ')'; ++i) {
    int k = s[i] == 'L' ? 0 : 1;
    if (!m->ch[k]) v[ve] = node(), m->ch[k] = &v[ve++];
    m = m->ch[k];
  }
  if (m->d != 0xDEADBEEF) dirty = 1;
  m->d = n;
}

bool bfs() {
  queue<node*> q; q.push(v);
  vi ans;
  while (!q.empty()) {
    node* u = q.front(); q.pop();
    if (u->d == 0xDEADBEEF) return false;
    ans.push_back(u->d);
    if (u->ch[0]) q.push(u->ch[0]);
    if (u->ch[1]) q.push(u->ch[1]);
  }
  for (auto i = ans.begin(); i != ans.end(); ) {
    cout << *i; cout << ((++i == ans.end()) ? '\n' : ' ');
  }
  return true;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(true);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(; !feof(stdin); --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    ve = 1; v[0] = node(); dirty = 0;
    bool in = false;
    while (scanf("%s", s) != EOF) {
      in = true;
      if (strcmp(s, "()") == 0) break;
      sscanf(s, "(%d,%s)", &n, s);
      add_node();
    }
    if (dirty || (in && !bfs())) cout << "not complete\n";
  }
  return 0;
}
