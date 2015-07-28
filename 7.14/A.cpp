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

struct Point{
	int x,y;
	Point (int x=0,int y=0):x(x),y(y){};
};


int n;
Point p[maxn];

bool cmp1(const Point &a,const Point &b)
{
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}


int main()
{
	cin>>n;
	int i;
	for(i=0;i<n;++i)
	scanf("%d%d",&p[i].x,&p[i].y);
	
	sort(p,p+n,cmp1);
	cout<<p[0].x<<endl;
	
	
    return 0;
}

