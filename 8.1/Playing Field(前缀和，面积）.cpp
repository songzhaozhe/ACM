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
const int maxn=5e5+100;
struct Point{
	double x,y;
	void read(){
		scanf("%lf%lf",&x,&y);
	}
};

double cross(Point a, Point b)
{
	return a.x * b.y - a.y * b.x;
}

double sum[maxn];
Point p[maxn];

int main()
{
	int n,q;
	int cas = 1;
//	while(cas++)
//	{
		scanf("%d%d",&n,&q);
	//	if(n == 0 && q == 0)return 0;
	//	if(cas!=2)puts("");
		
		for (int i = 0; i < n; ++i)
		{
			p[i].read();
		}
		sum[0]=cross(p[0],p[1]);
		for (int i = 1; i < n - 1; ++i)
		{
			sum[i] = sum[i-1] + cross(p[i],p[i+1]);
		}
		sum[n-1] = sum[n-2] + cross(p[n-1],p[0]);
		int x,y;
		for (int i = 0; i < q; ++i)
	{	scanf("%d%d",&x,&y);
		
		double area1 = -(sum[y-1] - sum[x-1] + cross(p[y],p[x]));
		double area2 = -(sum[n-1] - sum[y-1] + sum[x-1] + cross(p[x],p[y]));
	//	cout<<"###"<<area1<<' '<<area2<<endl;
		
		printf("%.3f\n",min(area1,area2)/2);
		} 
		
//	}
	
	
	
	return 0;
}


