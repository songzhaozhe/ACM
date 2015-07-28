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

const int maxn=200010;
const int INF=-199999999;
priority_queue<int>q;
int a[5],p1[5],p2[5];




void dfs1(int alr,int curnum)
{
	if(alr==4){q.push(curnum);return;}
	dfs1(alr+1,curnum+a[p1[alr]]);
	dfs1(alr+1,curnum*a[p1[alr]]);
	dfs1(alr+1,curnum-a[p1[alr]]);
	dfs1(alr+1,a[p1[alr]]-curnum);
	if(a[p1[alr]]!=0&&curnum%a[p1[alr]]==0)
	dfs1(alr+1,curnum/a[p1[alr]]);
	if(curnum!=0&&a[p1[alr]]%curnum==0)
	dfs1(alr+1,a[p1[alr]]/curnum);
	
	
	
	return;
}

void work(int x,int y)
{
	q.push(x+y);
	q.push(x*y);
	q.push(x-y);
	q.push(y-x);
	if(y!=0&&x%y==0)
	q.push(x/y); 
	if(x!=0&&y%x==0)
	q.push(y/x); 
}


void makey(int x)
{
	
	int y;
	y=a[p1[2]]+a[p1[3]];
	work(x,y);
	
	y=a[p1[2]]*a[p1[3]];
	work(x,y);
	y=a[p1[2]]-a[p1[3]];
	work(x,y);	
	if(a[p1[3]]!=0&&a[p1[2]]%a[p1[3]]==0)
	{
		y=a[p1[2]]/a[p1[3]];
		work(x,y);
	}
	
}


void check()
{
	dfs1(1,a[p1[0]]);
	//cout<<"@@"<<endl;
	int x,y;
	x=a[p1[0]]+a[p1[1]];
	makey(x);
//	cout<<"@@"<<endl;
	x=a[p1[0]]*a[p1[1]];	
	makey(x);	
	x=a[p1[0]]-a[p1[1]];	
	makey(x);	
	if(a[p1[1]]!=0&&a[p1[0]]%a[p1[1]]==0){
		x=a[p1[0]]/a[p1[1]];	
		makey(x);	
	}
} 



void make(int *A,int n,int alr)
{
	if(alr==n){
		//cout<<"##"<<endl;
		check();
		return;
	}
	int f[5]={0};
	int i;
	for(i=0;i<alr;++i)
	f[A[i]]=1;
	
	for(i=1;i<=n;++i)
	if(!f[i]){
		A[alr]=i;
		make(A,n,alr+1);
	} 	
}


int main()
{
	int i,maxx=0,begin,d[maxn],rear=-1,ans[maxn],cas=1;;
	scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
	while(a[1]!=0)
	{
		//while(!q.empty())q.pop();
		maxx=1;
		rear=-1;
		make(p1,4,0);
		//cout<<"##"<<endl;
		int tmp=q.top(),pre=tmp;
		while(!q.empty()) 
		{
			if(q.top()!=d[rear])
			d[++rear]=q.top();
			q.pop();			
		}
		ans[0]=1;
		begin=d[0];
		for(i=1;i<=rear;++i)
		{
			if(d[i-1]-d[i]==1)ans[i]=ans[i-1]+1;
			else ans[i]=1;
			if(ans[i]>maxx){
				maxx=ans[i];
				begin=d[i];
			}			
		}
		cout<<"Case "<<cas++<<": "<<begin<<" to "<<begin+maxx-1<<endl;
		
		scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
	}
	
	//100 100 100 100
    return 0;
}

