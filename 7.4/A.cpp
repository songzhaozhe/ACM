#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
//#include<cmath>
#include<map> 
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=20010;
const int INF=199999999;

int n,m,x1,x2,y1,y2;

struct Line{
	int u,l,num;
	
	bool operator <(const Line &a)const{
		return u<a.u;
	}
	
};
struct Point{
	int x,y;
};

int cross(const Point &a,const Point &b){
	return a.x*b.y-a.y*b.x;
}

bool operator <(const Point &p,const Line &b)
{
	int t=cross((Point){b.u-b.l,y1-y2},(Point){p.x-b.l,p.y-y2});
	return t>0;
 } 

bool operator <(const Line &b,const Point &p)
{
	int t=cross((Point){b.u-b.l,y1-y2},(Point){p.x-b.l,p.y-y2});
	return t<0;
 } 


Point p[maxn];
Line b[maxn];
int ans[maxn];
Line *t;


int main()
{
	scanf("%d",&n);
	while(n!=0)
	{
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		int i;
		for(i=1;i<=n;++i)
		{scanf("%d%d",&b[i].u,&b[i].l);b[i].num=i;}
		for(i=1;i<=m;++i)
		scanf("%d%d",&p[i].x,&p[i].y);
		
		//sort(b+1,b+n+1);
		b[0]=(Line){0,0,0};
		b[n+1]=(Line){x2,x2,n+1};
		
		for(i=0;i<=n;++i)
		{ans[i]=0;b[i].num=i;}
		
		int x=1;
		//cout<<b[n].u<<' '<<b[n].l<<endl;		cout<<p[m-1].x<<' '<<p[m-1].y<<endl;		if(b[n]<p[m-1])cout<<"yes"<<endl;		else cout<<"no"<<endl;
		
		
		
		for(i=1;i<=m;++i)
		{
			t=lower_bound(b,b+n+2,p[i]);
			//cout<<"p:"<<p[i].x<<' '<<p[i].y<<endl;cout<<t->num<<endl;
			
			
			++ans[t->num-1];
		}
		
		for(i=0;i<=n;++i)
		printf("%d: %d\n",i,ans[i]); 
		cout<<endl;
		
		
		
		scanf("%d",&n);
	}
	
	

	
	 
	
	
	
    return 0;
}

