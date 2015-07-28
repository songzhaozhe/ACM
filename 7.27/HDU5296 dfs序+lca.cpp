#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=200010;
const int INF=199999999;

struct Edgelist{
	int first[maxn],next[maxn],u[maxn],v[maxn],w[maxn];
	int rear;
	void init()
	{
		rear=-1;
		memset(first,-1,sizeof(first));
	}
	void add(int from,int to,int cost)
	{
		next[++rear]=first[from];
		first[from]=rear;
		u[rear]=from;
		v[rear]=to;
		w[rear]=cost;
		
		next[++rear]=first[to];
		first[to]=rear;
		u[rear]=to;
		v[rear]=from;
		w[rear]=cost;
	}
}e;

int m,n,ma[maxn];
int q[maxn];
int fa[maxn][30],dis[maxn],depth[maxn],dfn[maxn],flag[maxn],tot,cnt;

int LCA(int x,int y)
{
	if(depth[x]<depth[y])swap(x,y);
	int i,j;
	for(i=24;i>=0;--i)
	{
		if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(i=24;i>=0;--i)
	if(fa[x][i]!=fa[y][i])
	{
		x=fa[x][i];
		y=fa[y][i];
	}
	return fa[x][0];
}

void dfs(int x)
{
	if(dfn[x]!=-1)return;
	dfn[x]=++cnt;
	int j;
	for(j=e.first[x];j!=-1;j=e.next[j])
	{
		int y=e.v[j];
		if(dfn[y]!=-1)continue;
		fa[y][0]=x;
		depth[y]=depth[x]+1;
		dis[y]=dis[x]+e.w[j];
		dfs(y);
	}
}
	
set<int>s;
void solve()
{
	int i,j,x,y,oper,z,u,t;
	e.init();
	tot=0;
	s.clear();
	memset(flag,0,sizeof(flag));
	memset(dfn,-1,sizeof(dfn));
	memset(fa,-1,sizeof(fa));
	scanf("%d%d",&n,&m);
	for(i=1;i<n;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		e.add(x,y,z);
	}
	//BFS(1);
	fa[x][0]=0;
	cnt=0;
	dis[1]=0;
	depth[1]=1;
	dis[1]=0;
	dfs(1);
	for(i=1;i<=24;++i)
	for(j=1;j<=n;++j)
	{
		fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	for(i=1;i<=n;++i)
	ma[dfn[i]]=i;
	set<int>::iterator iter,iter2;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&oper,&u);
		if(oper==1&&flag[u]==0)
		{
			flag[u]=1;
			if(s.begin()==s.end()){
				s.insert(dfn[u]);
				printf("%d\n",tot);
				continue;
			}
			iter=s.lower_bound(dfn[u]);
			if(iter==s.begin()||iter==s.end())
			{
				x=ma[*(s.begin())];
				y=ma[*(--s.end())];
			}
			else{
				y=ma[*iter];
				x=ma[*(--iter)];
			}
			s.insert(dfn[u]);//dfn[u] - dfn[ lca(x,u) ] - dfn[ lca(y,u) ] + dfn[ lca(x,y) ]
//cout<<u<<' '<<x<<' '<<y<<endl;
//cout<<LCA(x,u)<<endl;
//cout<<LCA(y,u)<<endl;
//cout<<LCA(x,y)<<endl;

			tot+=dis[u]-dis[LCA(x,u)]-dis[LCA(y,u)]+dis[LCA(x,y)];
			printf("%d\n",tot);
		}
		else if(oper==2&&flag[u]==1)
		{
			flag[u]=0;
			iter=s.find(dfn[u]);
			if(iter==s.begin()||iter==(--s.end()))
			{
				s.erase(iter);
				x=ma[*(s.begin())];
				y=ma[*(--s.end())];
			}
			else{
				iter2=iter;
				x=ma[*(--iter2)];
				iter2=iter;
				y=ma[*(++iter2)];
				s.erase(iter);
			}
			//s.erase(iter);//dfn[u] - dfn[ lca(x,u) ] - dfn[ lca(y,u) ] + dfn[ lca(x,y) ]
			
		//	cout<<u<<' '<<x<<' '<<y<<endl;
			tot-=dis[u]-dis[LCA(x,u)]-dis[LCA(y,u)]+dis[LCA(x,y)];
			printf("%d\n",tot);
		}
		else printf("%d\n",tot);
	}
}
	
int main()
{
	int T;
	scanf("%d",&T);
	int cas;
	for(cas=1;cas<=T;++cas)
	{
		printf("Case #%d:\n",cas);
		solve();
	}	
	
    return 0;
}
/*
1
6 5
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
1 6
1 1
1 3
2 1
1 2


*/



