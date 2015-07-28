#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#define LL long long
using namespace std;


const int maxn=800;

inline double sqr(double x)
{
	return x*x;
}

struct Point{
	double x,y;
	inline Point operator *(double a)
	{
		return (Point){a*x,a*y};
	}
	inline Point operator /(double a)
	{
		return (Point){x/a,y/a};
	}
	inline Point operator -(const Point &b)const
	{
		return (Point){x-b.x,y-b.y};
	}
	inline Point operator +(const Point &b)const
	{
		return (Point){x+b.x,y+b.y};
	}
	inline double length()
	{
		return sqrt(sqr(x)+sqr(y));
	}
};


Point A,B,C,D,a,b,c,d,P,t,F,T;
double step[4]={2,0.01,0.0001,0.000002};


int main()
{

	while (1){		
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&D.x,&D.y);
		if(A.x==-1)break;
		P=A;
		int i,j,k;
		for(i=0;i<=3;++i)
		for(j=1;j<=maxn;++j)
		{
			a=A-P;
			if(a.length()>1e-12)
			a=a/a.length();
			b=B-P;
			if(b.length()>1e-12)
			b=b/b.length();
			c=C-P;
			if(c.length()>1e-12)
			c=c/c.length();
			d=D-P;
			if(d.length()>1e-12)
			d=d/d.length();
			F=a+b+c+d;
			if(F.length()<1e-12)
			{
				break;
			}
			T=F*step[i]/F.length();
			P=P+T;
		}
		double ll=0;
		ll=(A-P).length()+(B-P).length()+(C-P).length()+(D-P).length();
		
		
		printf("%.4f\n",ll);
	}
		

	
	return 0;
}
