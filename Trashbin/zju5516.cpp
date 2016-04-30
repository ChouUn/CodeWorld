//@ Including Header
#include <csl_std.h>

/**
 *  Name : zju5516.cpp
 *  Date : 2016年3月26日 下午2:30:26
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

const int N = 100010;
const ll P = 880803841;
//typedef std::vector<ll> vll;

struct node {
  bool lzy;
  int sum;
} t[N << 2];

inline void pushup(int id) {
  t[id].sum = t[id<<1].sum + t[id<<1|1].sum;
}

inline void pushdown(int id, int l, int r, int m) {
  if (t[id].lzy) {
    t[id].lzy = false;
    t[id<<1].lzy ^= true;
    t[id<<1].sum = m - l + 1 - t[id<<1].sum;
    t[id<<1|1].lzy ^= true;
    t[id<<1|1].sum = r - m - t[id<<1|1].sum;
  }
}

void build(int id, int l, int r) {
  t[id].lzy = false;
  t[id].sum = r - l + 1;
  if (l == r) return;

  int m = (l + r) >> 1;
  build(id<<1, l, m);
  build(id<<1|1, m+1, r);
}

void update(int id, int l, int r, int p, int q) {
  if (p <= l && r <= q) {
    t[id].lzy ^= true;
    t[id].sum = r - l + 1 - t[id].sum;
    return;
  }
  int m = (l + r) >> 1;
  pushdown(id, l, r, m);
  if (p <= m) update(id<<1, l, m, p, q);
  if (m < q) update(id<<1|1, m+1, r, p, q);
  pushup(id);
}

int query(int id, int l, int r) {
  return t[id].sum;
}

ll pm(ll e, ll n){
  ll ret = 1;
  for (; n; n >>= 1){
    if (n & 1){
      ret = ret * e % P;
    }
    e = e * e % P;
  }
  return ret;
}

ll fac[N], inv[N], a[N << 2], b[N << 2], ans[N << 2];
ll g = 26;

void ntt(ll *a, size_t n, bool inv = false){
    // inv?true??????;
    ll w=1,d=pm(g,(P-1)/n),t;
    size_t i,j,c,s;
    if(inv){
        for(i=1,j=n-1;i<j;swap(a[i++],a[j--]));
        for(t=pm(n,P-2),i=0;i<n;++i)a[i]=a[i]*t%P;
    }
    for(s=n>>1;s;s>>=w=1,d=d*d%P)
    for(c=0;c<s;++c,w=w*d%P)
    for(i=c;i<n;i+=s<<1){
        a[i|s]=(a[i]+P-(t=a[i|s]))*w%P;
        a[i]=(a[i]+t)%P;
    }
    for(i=1;i<n;++i){
        for(j=0,s=i,c=n>>1;c;c>>=1,s>>=1)j=j<<1|(s&1);
        if(i<j)swap(a[i],a[j]);
    }
}

void NTT(ll a[],int n1,ll b[],int n2,ll c[],int &l) {
  for (l=2;l<n1+n2-1;l<<=1);  //n+m???1
  rep(i, n1, l) a[i]=0;
  rep(i, n2, l) b[i]=0;
  ntt(a, l); ntt(b, l);
  rep(i, 0, l) c[i]=a[i]*b[i]%P;
  ntt(c, l, 1);
}

//@ Main Function
int main() {
  fac[0] = 1; rep(i, 1, N) fac[i] = fac[i-1] * i % P;
  inv[N-1] = pm(fac[N-1], P - 2); rrep(i, 1, N) inv[i-1] = inv[i] * i % P;

  std::ios_base::sync_with_stdio(false);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    //std::cout << "Case #" << __ << ": ";
    int n, m, d; cin >> n >> m >> d;

    rep(i, 0, m+1) a[i] = inv[i] * (i & 1 ? P - 1 : 1) % P;
//    rep(i, 0, m+1) b[i] = inv[i] * csl::pow(ll(1), ll(i), n, P) % P;
    rep(i, 0, m+1) b[i] = inv[i] * pm(i, n) % P;

    int l;
    NTT(a, m+1, b, m+1, ans, l);

    build(1, 1, m);

    while (d--) {
      int x, y; cin >> x >> y;
      update(1, 1, m, x, y);
      int z = query(1, 1, m); // cout << z << endl;
//      cout << (z ? ans[z] : 0) << endl;
      cout << (z ? ans[z] : 0) << endl;
    }
  }
  return 0;
}
