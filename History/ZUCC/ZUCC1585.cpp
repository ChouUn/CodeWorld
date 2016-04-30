/*
 *	Name : ZUCC1585.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月14日 下午12:21:50
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <iostream>
#include <stack>
#include <queue>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 1010
int a[maxN];

//@ Main Function
int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;

		queue<int> p;
		for (int i = 0; i < n; i++) {
			int in; cin >> in;

			p.push(in);
		}

		stack<int> q;
		bool ans = true;
		for (int i = 0; i < n; i++) {
			int in; cin >> in;
			if (q.empty() || q.top() != in) {
				while (!p.empty()) {
					int out = p.front();
					p.pop();
					q.push(out);
					if (out == in) break;
				}
			}
			if (q.empty() || q.top() != in)
				ans = false;
			q.pop();
		}
		cout << (ans ? "Yes." : "No.") << endl;
	}
	return 0;
}
