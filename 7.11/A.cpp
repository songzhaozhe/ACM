#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#define LL long long
using namespace std;

const int maxn=50010;
const int INF=199999999;

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){} 
};

double cross(Point &a,Point &b)
{
	return a.x*b.y-a.y*b.x;
 } 

int n,q,x,y;
Point p[maxn];
double s[maxn],sum;

int main()
{
	int flag=0;
	while(1){
		scanf("%d%d",&n,&q);
		if(n==0&&q==0)break;
		if(flag)printf("\n"); 
		flag=1;
	int i;
	for(i=0;i<n;++i)
	scanf("%lf%lf",&p[i].x,&p[i].y);//cout<<p[i].x<<' '<<p[i].y<<endl;
	
	s[0]=0;
	for(i=1;i<n;++i)
	s[i]=s[i-1]+cross(p[i-1],p[i]);//cout<<s[i]<<endl;
	sum=fabs(s[n-1]+cross(p[n-1],p[0]));
	while(q--)
	{
		scanf("%d%d",&x,&y);
		double s1=fabs(s[y]-s[x]+cross(p[y],p[x]));
		double ans=min(s1,sum-s1);
		//cout<<ans/2<<'\n';
		printf("%.1f\n",ans/2);
		
	}
	//printf("\n"); 
	
	//cin>>n>>q;
	}
	
    return 0;
}

