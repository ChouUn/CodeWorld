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
//@ Using Namespace
//using namespace std;
//@ Program Begin

#define maxN 1010
char str[maxN];
char stack[maxN];

//@ Main Function
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		int size = 0;
		bool ans = true;
		for (int i = 0; str[i]; i++) {
			if (str[i] == '{' || str[i] == '(')
				stack[size++] = str[i];
			else {
				if (str[i] == '}' && stack[size-1] == '{') {
					size--;
					continue;
				}
				if (str[i] == ')' && stack[size-1] == '(') {
					size--;
					continue;
				}
				ans = false;
			}
		}
		puts(ans ? "Yes." : "No.");
	}
	return 0;
}
