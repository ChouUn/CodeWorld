/*
	Name: BC29B.cpp
	Author: CHN.ChouUn
	Date: 2015年2月9日 下午4:02:03
	Copyright: www.fateud.com
	Email: ChouUnSoft@gmail.com
	Description: None
*/

#include <standard.h>
#include <ModInt.h>
#include <Matrix.h>

typedef ModInt<10000007> mInt;
typedef Matrix<mInt,3> Mat;

int n, k, a[100010];
int main() {
    while (cin >> n >> k) {
        REP(i,n) scanf("%d", a + i);
        sort(a, a + n);
        Mat p(1,3), q(3,3);
        // 重新构造了矩阵，p 分别为 an-2, an-1, sn-1
        p.at(0,0) = a[n-2]; p.at(0,1) = a[n-1]; p.at(0,2) = accumulate(a, a + n, mInt());
        // p * q 就是 an-1, an, sn
        q.at(0,0) = 0; q.at(0,1) = 1; q.at(0,2) = 1;
        q.at(1,0) = 1; q.at(1,1) = 1; q.at(1,2) = 1;
        q.at(2,0) = 0; q.at(2,1) = 0; q.at(2,2) = 1;
        // p * q ^ k，第三个数 sn 就是解了
        q = p * (q ^ k);
        mInt ans = q.at(0, 2);
        cout << ans.get() << endl;
    }
    return 0;
}
