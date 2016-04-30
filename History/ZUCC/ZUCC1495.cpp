/*
 *	Name : ZUCC1495.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月12日 上午7:13:17
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

#include<iostream>
#include<cstring>
using namespace std;

char s[30];
bool f[110];

int main(){
	int t; cin>>t;
	while(t--){
		memset(f, 0, sizeof(f));
		cin >> s;
		int len = strlen(s);
		int sum = 0; f[sum] = 1;
		for (int i = 0; i < len; i++)
			f[sum += s[i] - '0'] = true;
		if(((sum & 1) ^ 1) && f[sum / 2])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
