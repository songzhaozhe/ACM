#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=1000005;

struct Point{
	long double x,y;
	Point(long double x=0,long double y=0):x(x),y(y){}
	long double len(){
		return sqrt(x*x+y*y);
	}
	Point operator - (const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	Point operator + (const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator * (long double a)const{
		return Point(x*a,y*a);
	}
	Point operator / (long double a)const{
		return Point(x/a,y/a);
	}
	void read(){
		scanf("%Lf%Lf",&x,&y);
	}
	inline void print(){
	//	printf("%.5f %.5f\n",x,y);
	//int kk = 1;
	return ;
	
	}
}; 

Point p[3];
Point dir[4] = {Point(1,0),Point(0,1),Point(-1,0),Point(0,-1)};
Point t[3];

long double getvalue(Point t, int k){
	long double ans = 0;
	for (int i = 0; i < 3; ++i)
	if(i!=k)ans+=2*(p[i]-t).len();
	else ans+=(p[i]-t).len();
//	ans-=(p[k]-t).len();
	return ans;
}

long double cur[4];
long double eps = 1e-9;
int kk;
int main()
{
	int cas = 1;
	while(1){
		for (int i = 0; i < 3; ++i)
			p[i].read();
		if(p[0].x==-1)break;
		t[0] = (p[0]+p[1]+p[2])/3;
		t[1] = t[2] = t[0];
	//	t[0].print();
	//	t[1].print();
		for (int i = 0; i < 3; ++i)
		cur[i] = getvalue(t[i],i);//cout<<"###"<<cur[i]<<endl;}
		
		double sp = 4000;
		for (; sp > eps; sp*=.6)
		{
			//cout<<sp<<endl;
			//cout<<cur[1]<<endl;
			for (int i = 0; i < 3; ++i)
			{
					for (int j = 0; j < 4; ++j)
					{
						while(1){
						Point now;
						now = t[i] + dir[j]*sp;
					//	now.print();
						long double tmp = getvalue(now,i);
						if(tmp<cur[i]){
							cur[i] = tmp;
							t[i] = now;
						}
						else break;	
						}
					}					
				
			}		
		}
	//	for (int i = 0; i < 3; ++i)
		//{cout<<cur[i]<<endl;}
		printf("Case %d: %.8f\n",cas++,(double)min(min(cur[0],cur[1]),cur[2]));		
	}
	
	return 0;
}


