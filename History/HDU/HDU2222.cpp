/*
 *	Name : HDU2222.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月8日 下午8:58:37
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
//@ Using Namespace
using namespace std;
using namespace csl;
//@ Program Begin

#define maxL 55
#define maxM 10000
#define MAXL 1000010
#define maxN maxM*maxL

typedef ACsma::node node;
node g[maxN];
node* q[maxN];
char str[MAXL];

//@ Main Function
int main() {
	for (int T = getint(); T; T--) {
		int size = 1;
		memset(g, 0x00, sizeof(node));
		for (int n = getint(); n; n--) {
			scanf("%s", str);
			trie::insert(g, size, str, 1);
		}
		ACsma::build(g, q);
		scanf("%s", str);
		printf("%d\n", ACsma::match(g, str));
	}
	return 0;
}
