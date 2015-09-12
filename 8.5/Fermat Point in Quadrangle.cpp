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
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	double len(){
		return sqrt(x*x+y*y);
	}
	Point operator - (const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	Point operator + (const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator * (double a)const{
		return Point(x*a,y*a);
	}
	Point operator / (double a)const{
		return Point(x/a,y/a);
	}
	void read(){
		scanf("%lf%lf",&x,&y);
	}

}; 

double Cross(const Point &a, const Point &b){
	return a.x*b.y - a.y*b.x;
}

bool operator < (const Point &a, const Point &b){
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}

Point p[110],ch[110];
Point dir[4] = {Point(1,0),Point(0,1),Point(-1,0),Point(0,-1)};
Point t;
int n;
double getvalue(Point t){
	double ans = 0;
	for (int i = 0; i < n; ++i)
	ans+=(p[i]-t).len();

	return ans;
}

double cur;
double eps = 1e-3;

int ConvexHull(Point * p, int n, Point * ch){
	sort(p,p+n);
	int m = 0;
	for (int i = 0; i < n; ++i){
		while (m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n-2; i >= 0; i--){
		while (m > k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
		ch[m++] = p[i];
	}
	if(n>1)m--;
	return m;
}


int main()
{
	int cas = 1;
	int T;
	scanf("%d",&T);
	for(cas = 1; cas <= T; ++cas){
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
			{
				ch[i].read();
			}
		t = Point(0,0);
		n = ConvexHull(ch,n,p);
	//	t[0].print();
	//	t[1].print();
	
		cur = getvalue(t);//cout<<"###"<<cur[i]<<endl;}
		//cout<<cur<<endl;
		double sp = 20000;
		for (; sp > eps; sp*=.8)
		{
				//int cnt = 10;
				while(1){
					bool flag = 0;
					
					for (int j = 0; j < 4; ++j)
					{
						Point now;
						now = t + dir[j]*sp;
					//	now.print();
						double tmp = getvalue(now);
						if(tmp<=cur-1e-8){
							cur = tmp;
							t = now;
							flag = 1;
						//	cout<<cur<<endl;
							break;
						}								
					}
					if(!flag)break;						
				}
					
		}
	//	for (int i = 0; i < 3; ++i)
		//{cout<<cur[i]<<endl;}
		if(fabs(cur)<1e-4)cur = 0;
		printf("%d\n",int(cur+0.5));
		if(cas!=T)printf("\n");		
	}
	
	return 0;
}
