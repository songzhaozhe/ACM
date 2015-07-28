#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=1000005;

inline LL sqr(int x)
{
	return (LL)x*x;
}

struct Point{
	int x,y,z;
	void read(){
		scanf("%d%d%d",&x,&y,&z);
	}
	Point operator - (const Point &B)const{
		return (Point){ x - B.x, y - B.y, z - B.z};
	}
	LL len2()
	{
		return sqr(x) + sqr(y) + sqr(z);
	}
};

struct Plane{
	int a,b,c,d;
	void read(){
		scanf("%d%d%d%d",&a,&b, &c, &d);
	}
	int side(Point A)
	{
		if((LL)a * A.x + (LL)b * A.y + (LL)c * A.z + (LL)d > 0) return 1;
		else return -1;	
	}
	
}plane[110];

struct Sphere{
	Point c;
	int r;
	void read(){
		scanf("%d%d%d%d",&c.x,&c.y, &c.z, &r);
	}
}s[20];




int n,m,p,q;
Point poi[210];

int dis(const Point &A,const Point &B)
{
	int cnt = 0;
	for ( int i = 1; i <= n; ++i)
	{
		LL t1=((s[i].c - A).len2() - sqr (s[i].r));
		if(t1>0)t1=1;
		else t1=-1;
		LL t2=((s[i].c - B).len2() - sqr (s[i].r));
		if(t2>0)t2=1;
		else t2=-1;
		if(t1*t2<0)++cnt;
		
	}
	
	for ( int i = 1; i <= m; ++i)
		if( plane[i].side(A) * plane[i].side(B) < 0) ++cnt;
		
	return cnt;
}



int main()
{
	int x,y,z,T,flag;
	scanf("%d",&T);
	while(T--)
	{
		flag = 1;
		scanf("%d%d%d%d",&m,&n,&p,&q);
		for(int i = 1; i <= m; ++i)
		{
			plane[i].read();
		}
		for (int i = 1; i <= n; ++i)
		s[i].read();
		for (int i = 1; i <= p; ++i )
		{
			poi[i].read();
		}
		for(int i = 1; i <= p; ++i)
			for (int j = 1; j<= i; ++j)
			{
				if ( dis( poi[i], poi[j]) % 2 == 1)
				flag = 0;
			}
		Point A = poi[1];
		Point tmp;
		if(!flag)puts("Impossible");
		for( int i = 1; i <= q; ++i)
		{
			tmp.read();
			if(!flag)continue;
			if(p == 0) {
				puts("Both");
				continue;
			}
			if ( dis(A,tmp)%2==1)
				puts("R");
			else puts("Y");			
		}
		if(T!=0)puts("");
	}
	
	
	return 0;
}


