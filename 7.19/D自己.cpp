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

const int maxn=100010;
const int INF=199999999;

struct Edges{
	int first[maxn],next[maxn],v[maxn],w[maxn];
	int rear;	
	Edges(){
		memset(first,-1,sizeof(first));
		rear=-1;
	}
	void add(int from,int to,int wt)
	{
		next[++rear]=first[from];
		first[from]=rear;
		v[rear]=to;
		w[rear]=wt;
		
		next[++rear]=first[to];
		first[to]=rear;
		v[rear]=from;
		w[rear]=wt;
	}
}e;

int n,m,depth[maxn],p[maxn][20],dis[maxn];

void init()
{
	memset(p,0,sizeof(p));
	memset(dis,-1,sizeof(dis));
	vector<int>q;
	depth[1]=1;
	q.push_back(1);
	dis[1]=0;
	int i,j;
	for(i=0;i<q.size();++i)
	{
	//	cout<<i<<endl;
		int x=q[i];
		//cout<<x<<endl;
		for(int j=e.first[x];j!=-1;j=e.next[j])
		{
		//	cout<<x<<' '<<j<<' '<<e.v[j]<<endl;
			int to=e.v[j];
			if(dis[to]!=-1)continue;
			dis[to]=dis[x]+e.w[j];
			depth[to]=depth[x]+1;
			p[to][0]=x;
			for(int k=1;k<=18;++k)
			p[to][k]=p[p[to][k-1]][k-1];			
			q.push_back(to);			
		}
	}

				
	//for(i=0;i<n;++i)	
}

int lca(int a,int b)
{
	int i,j;
	if(depth[a]<depth[b])swap(a,b);

	for(i=18;i>=0;--i)
	if(depth[p[a][i]]>=depth[b])a=p[a][i];
	//cout<<a<<"###"<<b<<endl;
	if(a==b)return a;
	for(i=18;i>=0;--i)
		if(p[a][i]!=p[b][i]){
			a=p[a][i];
			b=p[b][i];
		}
	
	return p[a][0];
}
	


int main()
{
	scanf("%d",&n);
	int i,j,x,y,z;
	for(i=1;i<=n-1;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		++x;++y;
		e.add(x,y,z);
	}
	init();
	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		++x;++y;
		int t=lca(x,y);
		//cout<<t<<endl;
		printf("%d\n",dis[x]+dis[y]-2*dis[t]);
		
		
	}
    return 0;
}

