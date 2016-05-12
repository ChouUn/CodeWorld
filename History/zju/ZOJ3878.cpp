/*
 *	Name : zju3878.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015��4��25�� ����11:19:10
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stdc++.h>
//@ Using Namespace
using namespace std;
//@ Program Begin

char s[] = "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;\'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>? \n";
char t[] = "`1234567890[]~!@#$%^&*(){}\',.pyfgcrl/=\\\"<>PYFGCRL?+|aoeuidhtns-AOEUIDHTNS_;qjkxbmwvz:QJKXBMWVZ \n";
char p[256];

//@ Main Function
int main() {
  for (int i = 0; s[i]; i++) p[s[i]] = t[i];
  for (char c; scanf("%c", &c) != EOF; )
    printf("%c", p[c]);
  return 0;
}
