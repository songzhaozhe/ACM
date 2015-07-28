#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#define LL long long
using namespace std;

const int maxn=100010;
const int INF=199999999;

int T;
int n,m;
int first[500],next[maxn],v[maxn],edgerear=-1,in[maxn],vis[500],q[500],rear,pos[500];
void addedge(int from,int to){
	next[++edgerear]=first[from];
	first[from]=edgerear;
	v[edgerear]=to;
	
	next[++edgerear]=first[to];
	first[to]=edgerear;
	v[edgerear]=from;
}



void dfs(int x)
{
	//cout<<x<<endl;
	if(vis[x])return;
	vis[x]=1;
	if(in[x]==0)
	{
		q[++rear]=x;
		pos[x]=rear;
		for(int e=first[x];e!=-1;e=next[e])
		{
			if(e%2==1)continue;
			in[v[e]]--;
		}
		return;
	}
	
	int cnt=0,i,j;
	int pre[500];
	for(int e=first[x];e!=-1;e=next[e])
	{
		if(e%2==0)continue;
		int y=v[e];
		if(vis[y])continue;
		pre[++cnt]=y;
	//	vis[y]=1;
	}
	
	sort(pre+1,pre+cnt+1);
	for(i=1;i<=cnt;++i)
	dfs(pre[i]);
	
	if(in[x]==0){
		q[++rear]=x;
		pos[x]=rear;
		for(int e=first[x];e!=-1;e=next[e])
		{
			if(e%2==1)continue;
			in[v[e]]--;
		}		
	}
}


int main()
{
	scanf("%d",&T);
	int i,j,x,y;
	while(T--)
	{
		//int first[500],next[maxn],v[maxn],edgerear=-1,in[maxn],vis[500],q[500],rear,pos[500];
		memset(first,-1,sizeof(first));
		rear=0;
		edgerear=-1;
		memset(in,0,sizeof(in));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;++i)
		{
			scanf("%d%d",&x,&y);
			addedge(x,y);
			in[y]++;
		}
		for(i=1;i<=n;++i)
		dfs(i);
		
		if(rear!=n){
			printf("-1\n");
			continue;
		}
		for(i=1;i<n;++i)
		printf("%d ",pos[i]);
		printf("%d\n",pos[i]);
	}
		
		
	
	
    return 0;
}


/*
7
7 3
6 4
1 4
7 3
5 2 4 2 7 6 3

*/

