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

const int maxn=80100;
const int INF=199999999;

struct Edgelist{
	int v[maxn],w[maxn],u[maxn],first[maxn],next[maxn];
	int rear;
	void init(){
		 rear=-1;
		 memset(first,-1,sizeof(first));
	}
	void add(int from,int to,int weight)
	{
		next[++rear]=first[from];
		first[from]=rear;
		u[rear]=from;
		v[rear]=to;
		w[rear]=weight;
		
		next[++rear]=first[to];
		first[to]=rear;
		u[rear]=to;
		v[rear]=from;
		w[rear]=weight;	
	}
}e;

int depth[maxn],fa[maxn][30];
int q[maxn],dis[maxn];

void BFS(int s)
{
	int front=0,rear=-1;
	memset(fa,-1,sizeof(fa));
	fa[s][0]=0;
	dis[s]=0;
	q[++rear]=s;
	depth[s]=1;
	while(front<=rear)
	{
		int x = q[front++];
		for(int j=e.first[x];j!=-1;j=e.next[j])
		{
			int y=e.v[j];
			if(fa[y][0]!=-1)continue;
			fa[y][0]=x;
			dis[y]=dis[x]+e.w[j];
			depth[y]=depth[x]+1;
			q[++rear]=y;
		}
	}
	return;
}
			
int LCA(int x, int y)
{
	if(depth[x]<depth[y])swap(x,y);
	int i,j;
	for(i=20;i>=0;--i)
	{
		if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
	}
	if(x==y)return x;
	//cout<<"####"<<x<<' '<<y<<endl;
	for(i=20;i>=0;--i)
	{
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
	

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	int m,n;
	e.init();
	scanf("%d%d",&n,&m);
	int i,j,x,y,z;
	for(i=1;i<n;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		e.add(x,y,z);
	}
	BFS(1);
	for(i=1;i<20;++i)
	for(j=1;j<=n;++j)
	{
		fa[j][i]=fa[fa[j][i-1]][i-1];
	}
//	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		int t=LCA(x,y);
	//	cout<<"Pfa"<<t<<endl;
		printf("%d\n",dis[x]+dis[y]-2*dis[t]);
	}
	//if(T>0)printf("\n");
	
	}
	
    return 0;
}

