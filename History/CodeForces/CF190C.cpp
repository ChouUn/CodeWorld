/*
 *	Name: CF190C.cpp
 *	Author: CHN.ChouUn
 *	Date: 2015年2月9日 下午11:30:55
 *	Copyright: www.fateud.com
 *	Email: ChouUnSoft@gmail.com
 *	Description: None
 */

#include <standard.h>

#define maxN 100010
struct MyStack {
    int data[maxN];
    int size;
    bool first() {return data[size - 1];}
    bool second() {return data[size - 2];}
    bool third() {return data[size - 3];}
    void push(bool x) {data[size++] = x;}
    void pop() {size--;}
    MyStack() : size(0) {};
};
MyStack q;

int main() {
    int t;
    char s[20];
    scanf("%d", &t);
    string ans;
    while (t) {
        scanf("%s", s);
        ans += s;
        if (s[0] == 'i') {
            t--;
            q.push(1);
            while ( q.size >= 3 && q.first() && q.second() && (!q.third()) ) {
                ans += '>';
                q.pop(); q.pop(); q.pop();
                q.push(1);
            }
            if ( q.size && q.first() )
                ans += ",";
        }
        else if (s[0] == 'p') {
            q.push(0);
            ans += "<";
        }
    }
    if ((q.size > 1) || ((q.size == 1) && (q.data[0] == 0)) || (scanf("%s", s) != EOF) )
        ans = "Error occurred,";
    ans[ans.size() - 1] = '\n';
    cout << ans;
    return 0;
}
