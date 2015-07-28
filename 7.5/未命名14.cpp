#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
using namespace std;

const int maxn=20010;
const int INF=199999999;


#define MAXN 1000

struct HP
{
	int len,s[MAXN];
	HP()
	{
		memset(s,0,sizeof(s));
		len=1;
	}

	HP operator =(const char *num) //字符串赋值
	{
		len=strlen(num);
		for(int i=0;i<len;i++) s[i]=num[len-i-1]-'0';
	}

	HP operator =(int num) //int 赋值
	{
		char s[MAXN];
		sprintf(s,"%d",num);
		*this=s;
		return *this;
	}

	HP(int num) { *this=num;}

	HP(const char*num) {*this=num;}

	string str()const //转化成string
	{
		string res="";
		for(int i=0;i<len;i++) res=(char)(s[i]+'0')+res;
		if(res=="") res="0";
		return res;
	}

	HP operator +(const HP& b) const
    {
        HP c;
        c.len=0;
        for(int i=0,g=0;g||i<max(len,b.len);i++)
        {
        int x=g;
        if(i<len) x+=s[i];
        if(i<b.len) x+=b.s[i];
        c.s[c.len++]=x%10;
        g=x/10;
        }
        return c;
    }
    void clean()
    {
        while(len > 1 && !s[len-1]) len--;
    }

    HP operator *(const HP& b)
    {
        HP c;
        c.len=len+b.len;
        for(int i=0;i<len;i++)
        for(int j=0;j<b.len;j++)
            c.s[i+j]+=s[i]*b.s[j];
        for(int i=0;i<c.len-1;i++)
        {
        c.s[i+1]+=c.s[i]/10;
        c.s[i]%=10;
        }
        c.clean();
        return c;
    }

    HP operator - (const HP& b)
    {
        HP c;
        c.len = 0;
        for(int i=0,g=0;i<len;i++)
        {
        int x=s[i]-g;
        if(i<b.len) x-=b.s[i];
        if(x>=0)
            g=0;
        else
        {
            g=1;
            x+=10;
        }
        c.s[c.len++]=x;
        }
        c.clean();
        return c;
    }
    HP operator / (const HP &b)
    {
        HP c, f = 0;
        for(int i = len-1; i >= 0; i--)
        {
            f = f*10;
            f.s[0] = s[i];
            while(f>=b)
            {
                f =f-b;
                c.s[i]++;
            }
        }
        c.len = len;
        c.clean();
        return c;
    }
     HP operator % (const HP &b)
    {
        HP r = *this / b;
        r = *this - r*b;
        return r;
    }
    
     HP operator /= (const HP &b)
    {
        *this  = *this / b;
        return *this;
    }


    HP operator %= (const HP &b)
    {
        *this = *this % b;
        return *this;
    }
    
    bool operator < (const HP& b) const
    {
        if(len != b.len) return len < b.len;
        for(int i = len-1; i >= 0; i--)
        if(s[i] != b.s[i]) return s[i] < b.s[i];
            return false;
    }

    bool operator > (const HP& b) const
    {
        return b < *this;
    }

    bool operator <= (const HP& b)
    {
        return !(b < *this);
    }

    bool operator == (const HP& b)
    {
        return !(b < *this) && !(*this < b);
    }
    bool operator != (const HP &b)
    {
        return !(*this == b);
    }
    HP operator += (const HP& b)
    {
        *this = *this + b;
        return *this;
    }
    bool operator >= (const HP &b)
    {
        return *this > b || *this == b;
    }

   
};

istream& operator >>(istream &in, HP& x)
{
  string s;
  in >> s;
  x = s.c_str();
  return in;
}

ostream& operator <<(ostream &out, const HP& x)
{
  out << x.str();
  return out;
}




int main()
{
	HP a=1;
	HP b=9;
	HP c=b-a;
	cout<<c;
	
	
    return 0;
}

