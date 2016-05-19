/*
 *	Name : ZUCC1516.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月26日 下午9:04:17
 *	Copyright : www.fateud.com
 *	Description : None
 */

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int cir[105][105];
int c[105];
bool check(int n){
  int i,j,k;
  for(k = 1; k <= n; k++){
    for(i = 1; i <= n; i++)
      if(!c[i]) break;
    if(i==n+1) return false;
    c[i] = -1;
    for(j = 1; j <= n; j++){
      if(cir[i][j]){
        if (c[j] > 1) return false;
        c[j]--;
      }
    }
  }
  return true;
}
int main(){
  int T,Case = 1;
  int a,b,n,m;
  cin >> T;
  while(T--){
    memset(cir,0,sizeof(cir));
    memset(c  ,0,sizeof(c  ));
    cin >> n >> m;
    while(m--){
      cin >> a >> b;
      if(!cir[b][a]){
        cir[b][a] = 1;
        c[a]++;
      }
    }
    cout << "Case #" << Case++ << ": ";
    puts((check(n)) ? "Yes" : "No");
  }
}
