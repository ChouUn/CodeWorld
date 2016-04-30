/*
 *	Name : CF535A.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月18日 下午9:49:49
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

char low[][20] = {
"zero",
"one",
"two",
"three",
"four",
"five",
"six",
"seven",
"eight",
"nine",
"ten",
"eleven",
"twelve",
"thirteen",
"fourteen",
"fifteen",
"sixteen",
"seventeen",
"eighteen",
"nineteen",
};

char high[][20] = {
"",
"",
"twenty",
"thirty",
"forty",
"fifty",
"sixty",
"seventy",
"eighty",
"ninety",
};

//@ Main Function
int main() {
	int n; cin >> n;
	if (n < 20) {
		printf("%s\n", low[n]);
	}
	else {
		printf("%s", high[n/10]);
		if (n % 10 != 0)
			printf("-%s", low[n%10]);
		printf("\n");
	}
	return 0;
}
