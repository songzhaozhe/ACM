#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=20010;
const int INF=199999999;
const double PI=3.1415926; 

int n;
int a[10];
struct vec{
	double x,y;
}v[10];

double cross(vec a,vec b)
{
	return a.x*b.y-b.x*a.y;
}

double angle=0;

int main()
{
	int i;
	for(i=1;i<=6;++i)
	scanf("%d",&a[i]);
	for(i=1;i<=6;++i)
	{
		v[i].x=v[i-1].x+a[i]*cos(angle);
		v[i].y=v[i-1].y+a[i]*sin(angle);
		//cout<<v[i].x<<' '<<v[i].y<<endl;
		angle+=PI/3;
	}
	double size=0;
	for(i=1;i<=5;++i)
	size+=cross(v[i],v[i+1]); 
	size+=cross(v[6],v[1]);
	
	
	cout<<int(size*2/sqrt(3)+0.5)<<endl;
	
	
	
    return 0;
}

