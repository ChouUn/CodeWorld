#pragma comment(linker, /STACK:1024000000,1024000000)
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100010, SPLLEN = MAXN*20;
//-----------------------------------Splay Tree Start---------------------------
int SplaySize;
struct SplayNode
{
  int Value, Count, Size;
  SplayNode *Parent, *Child[2];
  void SetEMPTY() { Parent = Child[0] = Child[1] = this; }
} _splay[SPLLEN], _EMPTY;
SplayNode* const EMPTY = &_EMPTY;
struct Splay
{
  SplayNode* Root;
  SplayNode* Find(const int);
  SplayNode* Insert(const int);
  SplayNode* GetMin(SplayNode *);
  SplayNode* GetMax(SplayNode *);
  SplayNode* Join(SplayNode* const, SplayNode* const);
  void Erase(const int);
  int Rank(SplayNode* const, const int x);
  Splay(): Root(EMPTY) { }
private:
  void rotate(SplayNode *, const int);
  void splay(SplayNode *, SplayNode* const);
  void recount(SplayNode *); //Special Operate
};
inline void Splay::recount(SplayNode *x)
{
  x->Size = x->Child[0]->Size + x->Count + x->Child[1]->Size;
}
inline void Splay::rotate(SplayNode *x, const int c)
{
  SplayNode *y = x->Parent;
  y->Child[c^1] = x->Child[c];
  if (x->Child[c] != EMPTY)
    x->Child[c]->Parent = y;
  x->Parent = y->Parent;
  if (y->Parent != EMPTY)
    y->Parent->Child[y == y->Parent->Child[1]] = x;
  y->Parent = x;
  x->Child[c] = y;
//Special Operate:
  recount(y), recount(x);
}
inline void Splay::splay(SplayNode* x, SplayNode* const goal = EMPTY)
{
  for (SplayNode *y; (y = x->Parent) != goal; )
  {
    if (y->Parent == goal)
    {
      rotate(x, x == y->Child[0]);
      break;
    }
    const int c = y == y->Parent->Child[0];
    if (x == y->Child[c])
      rotate(x, c^1), rotate(x, c);
    else
      rotate(y, c), rotate(x, c);
  }
  if (goal == EMPTY)
    Root = x;
  recount(Root);
}
inline void Splay::Erase(const int value)
{
  SplayNode *node = Find(value);
  if (--node->Count)
  {
    recount(node);
    return;
  }
  Root = Join(node->Child[0], node->Child[1]);
  if (Root != EMPTY)
    Root->Parent = EMPTY;
  recount(Root);
  splay(Root);
}
inline SplayNode* Splay::Find(const int value)
{
  SplayNode *x = Root;
  while (x != EMPTY && x->Value != value)
    x = x->Child[value > x->Value];
  splay(x);
  return x;
}
inline SplayNode* Splay::Insert(const int value)
{
  SplayNode *node = _splay+(SplaySize++);
  node->Value = value;
  node->Child[0] = node->Child[1] = node->Parent = EMPTY;
  node->Count = node->Size = 1;
  if (Root == EMPTY)
    return Root = node;
  SplayNode *x = Root, *p = EMPTY;
  while (x != EMPTY)
  {
    if (value == x->Value)
    {
      node = x;
      ++x->Count;
      --SplaySize;
      recount(p);
      splay(node);
      return node;
    }
    p = x;
    x = x->Child[value > p->Value];
  }
  node->Parent = p;
  p->Child[value > p->Value] = node;
  recount(p); //Special Operate
  splay(node);
  return node;
}
inline SplayNode* Splay::GetMin(SplayNode* x = EMPTY) {
  if (x == EMPTY) x = Root;
  SplayNode* p = EMPTY;
  while (x != EMPTY)
  {
    p = x;
    x = p->Child[0];
  }
  if (p != EMPTY) splay(p);
  return p;
}
inline SplayNode* Splay::GetMax(SplayNode* x = EMPTY) {
  if (x == EMPTY) x = Root;
  SplayNode* p = EMPTY;
  while (x != EMPTY) {
    p = x;
    x = p->Child[1];
  }
  if (p != EMPTY) splay(p);
  return p;
}
inline SplayNode* Splay::Join(SplayNode* const lef, SplayNode* const rig) {
  if (lef == EMPTY) return rig;
  if (rig == EMPTY) return lef;
  SplayNode* node = GetMax(lef);
  node->Child[1] = rig;
  rig->Parent = node;
  recount(node);
  splay(node);
  return node;
}
inline int Splay::Rank(SplayNode* const node, const int value) {
  if (node == EMPTY) return 0;
  if (value < node->Value) return Rank(node->Child[0], value);
  return Rank(node->Child[1], value) + node->Count + node->Child[0]->Size;
}
//-----------------------------------Splay Tree  End ---------------------------
int TestData, n, m, a[MAXN];
Splay C[MAXN];
int Query(int x, const int value) {
  int res = 0;
  while (x > 0) {
    res += C[x].Rank(C[x].Root, value);
    x -= x&-x;
  }
  return res;
}
void Modify(int x, const int value) {
  while (x <= n) {
    C[x].Insert(value);
    x += x&-x;
  }
}
void Remove(int x, const int value) {
  while (x <= n) {
    C[x].Erase(value);
    x += x&-x;
  }
}
int GetMin(int x) {
  int res = 0x7FFFFFFF;
  while (x > 0) {
    res = std::min(res, C[x].GetMin()->Value);
    x -= x&-x;
  }
  return res;
}
int GetMax(int x) {
  int res = 0;
  while (x > 0) {
    res = std::max(res, C[x].GetMax()->Value);
    x -= x&-x;
  }
  return res;
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a+i);
    Modify(i, a[i]);
  }
  scanf("%d", &m);
  while (m--) {
    int c; scanf("%d", &c);
    if (c == 2) {
      int st, ed, k;
      scanf("%d%d%d\n", &st, &ed, &k);
      int lef = GetMin(n)-1, rig = GetMax(n)+1;
      while (lef+1 < rig) {
        const int mid = (lef+rig)/2;
        const int tmp1 = Query(st-1, mid), tmp2 = Query(ed, mid);
        if (tmp2-tmp1 >= k)
          rig = mid;
        else
          lef = mid;
      }
      printf("%d\n", rig);
    }
    else {
      int index, value;
      scanf("%d%d\n", &index, &value);
      Remove(index, a[index]);
      a[index] = value;
      Modify(index, value);
    }
  }
}
int main()
{
  _EMPTY.SetEMPTY();
//  scanf("%d", &TestData);
//  while (TestData--)
//  {
  while (scanf("%d", &n) != EOF) {
    SplaySize = 0;
    solve();
    memset(_splay, 0, sizeof(_splay[0])*SplaySize);
    for (int i = 1; i <= n; ++i) C[i] = Splay();
  }
//  }
}
