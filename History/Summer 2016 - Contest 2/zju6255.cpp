//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju6255.cpp
 *  Date : 2016年7月6日 上午10:38:53
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define CLR(a,v) memset(a,v,sizeof(a))

const ll mod = 1000000007;
const int N = 1010;
const int M = 510;

namespace Trie
{
  const int Size = 26;
  int top;
  struct Node{
    Node *next[Size], *f;
    //int ended_cnt;
    int ended_val;
  }node[M], *root;
  inline Node* new_node()
  {
    //node[top].ended_cnt = 0;
    node[top].ended_val = 0;
    CLR(node[top].next,0);
    return &node[top++];
  }
  void init()
  {
    top = 0;
    root = new_node();
  }
  void insert(char *s,int val=1)
  {
    Node *u = root;
    for(int i=0;s[i];i++)
    {
      int id = s[i] - 'a';
      if(u->next[id] == NULL)
        u->next[id] = new_node();
      u = u->next[id];
    }
    //u->ended_cnt++;
    u->ended_val = val;
  }
}

namespace ACam
{
  using namespace Trie;
  void get_fail()
  {
    queue<Node*> Q;
    for(int i=0;i<Size;i++)
    {
      Node *&ch = root->next[i];
      if(!ch)
        ch = root;
      else
      {
        ch->f = root;
        Q.push(ch);
      }
    }
    while(!Q.empty())
    {
      Node *cur = Q.front();Q.pop();
      for(int i=0;i<Size;i++)
      {
        Node *&ch = cur->next[i];
        if(!ch)
          ch = cur->f->next[i];
        else
        {
          ch->f = cur->f->next[i];
          ch->ended_val |= ch->f->ended_val;
          Q.push(ch);
        }
      }
    }
  }
  int dp[N][M];
  int bit_cnt[2];
  void pre()
  {
    bit_cnt[0] = 0;
    bit_cnt[1] = 1;
  }
  int solve(int n, int m)
  {
    //memset(dp,0,sizeof(dp));      //TLE
    for(int i=0;i<=n;i++)
      for(int j=0;j<top;j++) dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i=0;i<n;i++) {
      for(int j=0;j<top;j++) {
        if(!dp[i][j]) continue;
        for(int kk=0;kk<Size;kk++)
        {
          int jj = node[j].next[kk] - node;
          if (node[jj].ended_val) continue;
          (dp[i+1][jj] += dp[i][j]) %= mod;
        }
      }
    }
    int ans = 0;
    for(int j=0;j<top;j++)
      (ans += dp[n][j]) %= mod;
    return ans;
  }
}

char str[M];
//@ Main Function
int main() {
  ACam::pre();

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n,m; cin >> n >> m;
    ACam::init();
    rep(i, 0, m) {
      cin >> str;
      ACam::insert(str, 1);
    }
    ACam::get_fail();
    int ans = ACam::solve(n,m);
    cout << ans << endl;
  }
  return 0;
}
