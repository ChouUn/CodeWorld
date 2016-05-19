/*
大整数可正负，包括比较运算，加减乘，自加自减自乘
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=1010;

struct BigInteger
{
    int sign,len,s[MAX];//sign为1表示正，-1表示负。
    BigInteger()
    {
        memset(s,0,sizeof(s));
        len=1;
        sign=1;
    }
    void jud()//避免出现-0以及前导0这样的情况。
    {
        bool zero=true;
        for(int i=MAX-1; i>=0; i--)if(s[i]!=0)
            {
                len=i+1;
                zero=false;
                break;
            }
        if(zero)
        {
            len=1;
            sign=1;
        }
    }
    void output()
    {
        if(sign==-1)printf("-");
        for(int i=len-1; i>=0; i--)printf("%d",s[i]);
    }

    BigInteger operator = (const char* num)
    {
        int g=0;
        if(num[0]=='-')
        {
            sign=-1;
            g=1;
        }
        len=strlen(num);
        for(int i=0; i<len-g; i++)s[i]=num[len-i-1]-'0';
        return *this;
    }
    BigInteger operator = (int num)//请不要使用 BigInteger x=123 这样的操作。//此函数于测试中。
    {
        char s[MAX];
        sprintf(s,"%d",num);
        *this=s;
        return *this;
    }
    BigInteger(int num)
    {
        *this=num;
    }
    BigInteger(const char* num)
    {
        *this=num;
    }
//////////////////////////////////////////////////////////////////////////////////////////////比较运算。
    bool abs_cmp (const BigInteger& b) const//比较绝对值。
    {
        if(len!=b.len)return len<b.len;
        for(int i=len-1; i>=0; i--)
            if(s[i]!=b.s[i])return s[i]<b.s[i];
        return false;
    }
    bool operator < (const BigInteger& b) const
    {
        if(sign!=b.sign)return sign<b.sign;
        if(sign==1&&b.sign==1)return abs_cmp(b);
        else return !abs_cmp(b);
    }
    bool operator > (const BigInteger& b) const
    {
        return b<*this;
    }
    bool operator <= (const BigInteger& b) const
    {
        return !(b<*this);
    }
    bool operator >= (const BigInteger& b) const
    {
        return !(*this<b);
    }
    bool operator != (const BigInteger& b) const
    {
        return b<*this||*this<b;
    }
    bool operator == (const BigInteger& b) const
    {
        return !(b<*this)&&!(*this<b);
    }
////////////////////////////////////////////////////////////////////////////////////////////基本运算。

    BigInteger operator + (const BigInteger& b) const
    {
        BigInteger c,d,e;
        c.len=0;
        if(sign==1&&b.sign==1||sign==-1&&b.sign==-1)
        {
            c.sign=sign;
            for(int i=0,g=0; g||i<max(len,b.len); i++)
            {
                int x=g;
                if(i<len)x+=s[i];
                if(i<b.len)x+=b.s[i];
                c.s[c.len++]=x%10;
                g=x/10;
            }
        }
        else
        {
            if(abs_cmp(b))
            {
                e=b;
                d=*this;
            }
            else
            {
                d=b;
                e=*this;
            }
            for(int i=0; i<e.len; i++)
            {
                c.s[i]=(e.s[i]+10-d.s[i])%10;
                if(e.s[i]<d.s[i])
                {
                    int j=i+1;
                    while(e.s[j]<=0)
                    {
                        e.s[j]=(e.s[j]+9)%10;
                        j++;
                    }
                    e.s[j]=(e.s[j]+9)%10;
                }
            }
            if(sign==1&&b.sign==-1&&abs_cmp(b))c.sign=-1;
            if(sign==1&&b.sign==-1&&!abs_cmp(b))c.sign=1;
            if(sign==-1&&b.sign==1&&abs_cmp(b))c.sign=1;
            if(sign==-1&&b.sign==1&&!abs_cmp(b))c.sign=-1;
        }
        c.jud();
        return c;
    }

    BigInteger operator += (const BigInteger& b)
    {
        *this=*this+b;
        return *this;
    }
    BigInteger operator - (const BigInteger& b) const
    {
        BigInteger c,d;
        d=b;
        d.sign*=-1;
        c=*this+d;
        c.jud();
        return c;
    }
    BigInteger operator -= (const BigInteger& b)
    {
        *this=*this-b;
        return *this;
    }

    BigInteger operator * (const BigInteger& b) const//复杂度O(n^2)
    {
        BigInteger c;
        for(int i=0; i<len; i++)
            for (int j=0; j<b.len; j++)
            {
                c.s[i+j]+=s[i]*b.s[j];
                c.s[i+j+1]+=c.s[i+j]/10;
                c.s[i+j]%=10;
            }
        c.jud();
        return c;
    }
    BigInteger operator *= (const BigInteger& b)
    {
        *this=*this*b;
        return *this;
    }

};



int main()
{

    return 0;
}

