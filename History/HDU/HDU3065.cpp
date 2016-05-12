/*
 *	Name : HDU3065.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��9�� ����2:26:54
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
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


int decode(char word) {
	if (isupper(word))
		return (word & 0x1f);
	return 0;
}

//@ trie�ֵ���
namespace trie
{
	const static int MAXC = 27;

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
			int ch = decode(*word);
			if (!prev->next[ch]) {
				_Node* tmp = root + (size++);
				memset(tmp, 0x00, sizeof(_Node));
				prev->next[ch] = static_cast<trie::node*>(tmp);
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
		int count;
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

	void
	find(node* root, char* word)
	{
		for (node* index = 0; *word; word++) {
			int ch = decode(*word);
			while (index && !index->next[ch]) index = index->fail;
			index = (index) ? (index) : (root);
			index = static_cast<node*>(index->next[ch]);
			for (node* tmp = index; tmp; tmp = tmp->fail) {
				if (tmp->data) tmp->count++;
			}
		}
	}

} // namespace ACauto

//@ Using Namespace
using namespace std;
using namespace csl;
//@ Program Begin

#define maxl 60
#define maxN 1010
#define maxL 2000010
typedef ACsma::node node;

char str[maxL];
node g[maxl*maxN];
node* f[maxl*maxN];
string ans[maxN];
int cnt[maxN];

void dfs(node* prev, string s) {
	if (!prev) return;
	if (prev->data && prev->count)
		ans[prev->data] = s, cnt[prev->data] = prev->count;
	for (int i = 1; i < trie::MAXC; i++) {
		if (prev->next[i])
			dfs(static_cast<node*>(prev->next[i]), s + (char)(i | 0x40));
	}
}

//@ Main Function
int main() {
	for (int n; ~scanf("%d", &n);) {
		memset(g, 0x00, sizeof(g[0]));
		for (int size = 1, i = 1; i <= n; i++) {
			scanf("%s", str);
			ACsma::insert(g, size, str, i);
		}
		ACsma::build(g, f);

		memset(cnt, 0x00, sizeof(cnt));
		scanf("%s", str);
		ACsma::find(g, str);

		dfs(g, "");
		for (int i = 1; i <= n; i++)
			if (cnt[i])
				cout << ans[i] << ": " << cnt[i] << endl;
	}
	return 0;
}
