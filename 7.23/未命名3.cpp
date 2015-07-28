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

const int maxn=110;
const int INF=199999999;

int n,m,a[maxn][maxn],d[maxn][maxn],vis[maxn][maxn],q[400000],rear,num[maxn][maxn];
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};

int solve()
{
	int cnt=0;
	rear=-1;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		scanf("%d",&a[i][j]);
		d[i][j]=1;
		q[++rear]=i*51+j;
		vis[i][j]=1;
		num[i][j]=1;
	}
	int maxx=1,front=0;
	while(front<=rear)
	{
		int tmp=q[front++];
		int x=tmp/51,y=tmp%51;
		vis[x][y]=0;
		for(i=0;i<=3;++i)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(a[nx][ny]<a[x][y])
			{if(d[nx][ny]<d[x][y]+1)
			{
				d[nx][ny]=d[x][y]+1;
				num[nx][ny]=num[x][y];
				maxx=max(maxx,d[nx][ny]);
				if(!vis[nx][ny])
				{
					q[++rear]=nx*51+ny;
					vis[nx][ny]=1;
				}
			}
			else if(d[nx][ny]==d[x][y]+1)
			{
				num[nx][ny]+=num[x][y];
			}
			}
		}
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(d[i][j]==maxx)cnt++;
	return  cnt;
}
	
	

int main()
{
	int T;
	scanf("%d",&T);
	int cas=1;
	for(;cas<=T;++cas)
	{
		printf("Case #%d: %d\n",cas,solve());
	}	
    return 0;
}/*

4 4 5 1 5 3 2 2 4 4 2 1 7 10 9 6 8 5 2 1 5 3 4 3 4 8 8 8 8 8 8 8 8 8 8 8 8 2 5 2 1 6 7 8 6 7 1 4 5 1 10 4 3 2 1 2 3 4 5 6 7 
