/*
 *	Name : ZUCC1584.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月13日 下午9:05:24
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <cstdio>
#include <stack>
//@ Using Namespace
using namespace std;
//@ Program Begin

#define maxN 1010
char str[maxN];

stack<char> q;
bool check(char ch) {
	if (q.empty() || q.top() != ch)
		return false;
	return true;
}

//@ Main Function
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		bool ans = true;
		while (!q.empty()) q.pop();
		for (int i = 0; str[i]; i++) {
			if (str[i] == '{' || str[i] == '(')
				q.push(str[i]);
			else {
				if (str[i] == '}' && check('{'))
					q.pop();
				else if (str[i] == ')' && check('('))
					q.pop();
				else
					ans = false;
			}
		}
		puts((ans && q.empty()) ? "Yes." : "No.");

	}
	return 0;
}
