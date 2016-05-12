/*
 *	Name : HDU2896.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��9�� ����1:45:31
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#define CSL_STD_CONTAINER

/*
 *	Name : ChouUn's Standard Library ֽũ�α�׼��
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 */

#ifndef _TEMPLATE_CSL_STD
#define _TEMPLATE_CSL_STD 1
#define _TEMPLATE_CSL_STD_VERSION 20150409A

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>

#define FOR(i,m,n)	for(int _s=m, _t=n+1-2*((n)<(m)), _d=1-2*((n)<(m)), i=_s; i!=_t; i+=_d)
#define REP(i,n)	for(int _t=n, i=0; i<_t; i+=1)
#define per(i,n)	for(int i=n-1; i>=0; i-=1)

typedef long long Int64;
namespace csl {
	template <typename _Tp> _Tp sqr(_Tp x) { return x * x; }
	template <typename _Tp> bool exmax(_Tp &a, const _Tp b) { return (a < b) ? (a = b) || 1 : 0; }
	template <typename _Tp> bool exmin(_Tp &a, const _Tp b) { return (a > b) ? (a = b) || 1 : 0; }
	inline int getint() {
		int ret = 0; bool ok = 0, neg = 0; while (int c = getchar()) {
		if (c >= '0' && c <= '9') ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
		else if (ok) break; else if (c == '-') neg = 1; } return neg ? -ret : ret;
	}
}

#ifdef CSL_STD_CONTAINER
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bits/stl_list.h>
#include <bits/stl_deque.h>
#include <bits/stl_vector.h>
#define mp(a,b)			make_pair(a,b)
typedef std::pair<int,int>	pii;
typedef std::vector<int>	vi;
typedef std::vector<pii>	vpii;
#define TRV(i,n)		for(__typeof((n).begin())  i=(n).begin(); i!=(n).end(); i++)
#define RTRV(i,n)		for(__typeof((n).rbegin()) i=(n).rbegin();i!=(n).rend();i++)
#endif /* CSL_STD_CONTAINER */

#ifdef CSL_STD_DEBUG
#include <time.h>
#include <assert.h>
#include <sstream>
#include <fstream>
#include <limits>
#define PAUSE()		system("pause")
#define PRINT(x)	cout << #x << " = " << x << endl
#endif /* CSL_STD_DEBUG */

#endif	/* _TEMPLATE_CSL_STD */


//@ trie�ֵ���
namespace trie
{
	const static int MAXC = 128;

	struct node
	{
		node* next[MAXC];
		int data;
	};

	template <typename _Node>
	void
	insert(_Node* root, int& size, char* word, int data)
	{
		_Node* prev = root;
		for (; *word; word++) {
			int ch = (*word) - 1;
			if (!prev->next[ch]) {
				_Node* tmp = root + (size++);
				memset(tmp, 0x00, sizeof(_Node));
				prev->next[ch] = static_cast<node*>(tmp);
			}
			prev = static_cast<_Node*>(prev->next[ch]);
		}
		prev->data = data;
	}

} // namespace trie

//@ AC�Զ�����ģʽ�ַ���ƥ���㷨
namespace ACsma
{
	struct node :
		public trie::node
	{
		node* fail;
	};

	inline void
	insert(node* root, int& size, char* word, int data)
	{
		trie::insert(root, size, word, data);
	}

	void
	build(node* root, node** queue)
	{
		int head = 0, tail = 0;
		root[0].fail = 0;
		queue[tail++] = root;
		while (head ^ tail) {
			node* prev = queue[head++];
			for (int ch = 0; ch < trie::MAXC; ch++) {
				if (node* next = static_cast<node*>(prev->next[ch])) {
					next->fail = root;
					for (node* tmp = prev->fail; tmp; tmp = tmp->fail) {
						if ((next->fail = static_cast<node*>(tmp->next[ch]))) break;
					}
					queue[tail++] = next;
				}
			}
		}
	}

	std::set<int>
	find(node* root, char* word)
	{
		std::set<int> ret;
		for (node* index = 0; *word; word++) {
			int ch = (*word) - 1;
			while (index && !index->next[ch]) index = index->fail;
			index = (index) ? (index) : (root);
			index = static_cast<node*>(index->next[ch]);
			for (node* tmp = index; tmp; tmp = tmp->fail) {
				if (tmp->data) ret.insert(tmp->data);
				if (ret.size() >= 3) return ret;
			}
		}
		return ret;
	}

} // namespace ACauto

//@ Using Namespace
using namespace std;
using namespace csl;

//@ Program Begin
#define	maxl		210
#define maxN		510
#define	maxL		10010
typedef	ACsma::node	node;

char str[maxL];
node g[maxl*maxN];
node* f[maxl*maxN];

//@ Main Function
int main() {
	for (int m = getint(), i = 1, size = 1; i <= m; i++) {
		scanf("%s", str);
		ACsma::insert(g, size, str, i);
	}

	ACsma::build(g, f);

	int ans = 0;
	for (int n = getint(), i = 1; i <= n; i++) {
		scanf("%s", str);
		set<int> tmp = ACsma::find(g, str);
		if (tmp.empty()) continue;
		printf("web %d:", i);
		TRV(j, tmp) printf(" %d", *j);
		printf("\n");
		ans++;
	}
	printf("total: %d\n", ans);
	return 0;
}
