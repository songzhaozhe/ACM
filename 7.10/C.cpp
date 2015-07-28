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

const int maxn=20010;
const double INF=199999999;

int n,m,w[17],g[17][17],q[17],rear;
double minn=INF;
int ans[17];

struct pii{
	int first,second;
};
bool operator <(pii a,pii b)
{
	return b.second<a.second;
}


double cal()
{
	int ew=0,nw=0;
	priority_queue<pii >Q;
	int i,j,is[17]={0},y;
	pii x;
	for(i=1;i<=m;++i)
	{
		nw+=w[q[i]];
		is[q[i]]=1;
	}
	int flag[17]={0};
	flag[q[1]]=1;
	int cnt=1;
	for(i=1;i<=n;++i)
	if(!flag[i]&&is[i])Q.push((pii){i,g[q[1]][i]});
	while(cnt<m)
	{
		x=Q.top();
	//	cout<<q[1]<<' '<<x.second<<"####"<<endl;
		Q.pop();
		if(flag[x.first])continue;
		ew+=x.second;
		flag[x.first]=1;
		++cnt;
		for(i=1;i<=n;++i)
		if(is[i]&&!flag[i])Q.push((pii){i,g[x.first][i]});		
	}
	
//	cout<<ew<<' '<<nw<<endl;
	return 1.0*ew/nw;
}

void copy()
{
	for(int i=1;i<=m;++i)
	ans[i]=q[i]; 	
}

void dfs(int cur)
{
	if(cur==m)
	{
		double t=cal();
	//	for(int i=1;i<=m;++i)
	//	cout<<q[i]<<' ';
	//	cout<<"###"<<t<<endl;
		if(t<minn){minn=t;copy();}
		return;
	}
	int i;
	for(i=q[cur]+1;i<=n;++i)
	{
		q[cur+1]=i;
		dfs(cur+1);	
	}
}

void work()
{
//	sort(q,q+rear+1);
	minn=INF;
//	rear=0;
	dfs(0);
	for(int i=1;i<m;++i)
	cout<<ans[i]<<' ';
	cout<<ans[m]<<'\n';	
}

int main()
{
	int i,j;
	q[0]=0;
	scanf("%d%d",&n,&m);
	while(!(n==0&&m==0))
	{
		for(i=1;i<=n;++i)
		scanf("%d",&w[i]);
		//rear=-1;
		for(i=1;i<=n;++i)for(j=1;j<=n;++j){
			scanf("%d",&g[i][j]);
		//	if(i>j)q[++rear]=g[i][j];
		}
		
			
		work();
		
		scanf("%d%d",&n,&m);
	}
	
	
	
    return 0;
}

