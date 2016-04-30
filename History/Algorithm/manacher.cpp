/*
 *	Name : manacher.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月13日 下午11:26:14
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <bits/stl_algobase.h>
//@ Program Begin

//@ manacher算法 求最长回文字串
namespace manacher
{
	// s是初始数组，t是目标数组
	void build(char s[], char t[])
	{
		int p = 0; t[p++] = '$', t[p++] = '#';
		for (int i = 0; s[i]; i++) t[p++] = s[i], t[p++] = '#';
		t[p] = 0;
	}
	// s是初始数组，f是辅助数组
	int solve(char s[], int f[])
	{
	    int ret = 0;
	    for (int md = 0, mi = 0, i = 1; s[i]; i++) {
	        f[i] = (md > i) ? (std::min(f[2 * mi - i], md - i)) : (1);
	        while (s[i + f[i]] == s[i - f[i]]) f[i]++;
	        if (md < i + f[i]) mi = i, md = i + f[i];
	        if (f[i] > ret) ret = f[i];
	    }
	    return ret - 1;
	}

} // namespace manacher
