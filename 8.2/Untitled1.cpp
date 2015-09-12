#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxe=2e5+100;
const int maxv=1e5+100;



int n,m,Q;
int deg[maxv];
int fa[maxv];
vector<pair<int, int> >e[maxv];
vector<pair<int,int> >q[maxv];
bool vis[maxv];


inline int find(int x)
{
	if(fa[x]==-1)return x;
	else return fa[x] = find(fa[x]);	
}
void merge(int x, int y)
{
	int xx = find(x),yy = find(y);
	if(xx==yy)return;
	fa[xx] = yy;
	return;
}
int ans[maxv];
int mm,tot=0;
int dis[500][maxv];
int pos[maxv];

void work(int a,int col)
{
	for (int k = 0; k < q[a].size(); ++k)
	{
		int b = q[a][k].first;
		if(find(a)==find(b)){
		ans[q[a][k].second]++;
		}					
	}
}

void work1(int col)
{
	vector<int>a;
	for (int i = 0; i <e[col].size(); ++i)
	{
		int x = e[col][i].first, y = e[col][i].second;
		a.push_back(x);
		a.push_back(y);
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	for (int i = 0; i < a.size(); ++i)
	if(deg[a[i]]>mm){
		for (int j = 0; j < a.size();++j)
		if(i==j)continue;
		else if(find(a[i])==find(a[j]))dis[pos[a[i]]][a[j]]++;
	}
}

int main()
{

	memset(fa,-1,sizeof(fa));
	scanf("%d%d",&n,&m);
	int a,b,c;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		e[c].push_back(make_pair(a,b));
		deg[a]++;
		deg[b]++;
	}
	mm = sqrt(m);
	for (int i = 1; i <= n; ++i)
	pos[i] = ++tot;
	
	scanf("%d",&Q);
	for (int i = 1; i <= Q; ++i)
	{
		scanf("%d%d",&a,&b);
		if(deg[a]>deg[b])swap(a,b);
		q[a].push_back(make_pair(b,i));	
	}
	for (int i = 1; i <= m; ++i)
	{
		if(!e[i].size())continue;
		for (int j = 0; j < e[i].size(); ++j)
		{
			merge(e[i][j].first,e[i][j].second);
		}
		work1(i);
		for (int j = 0; j < e[i].size(); ++j)
		{
			int a = e[i][j].first;
			if(!vis[a]&&deg[a]<=mm){
				vis[a] = 1;
				work(a,i);
			}
			a = e[i][j].second;
			if(!vis[a]&&deg[a]<=mm){
				vis[a] = 1;
				work(a,i);
			}
		}
		for (int j = 0; j < e[i].size(); ++j)
		{
			int x = e[i][j].first,y = e[i][j].second;
			vis[x]=vis[y]=0;
			fa[x] = -1;
			fa[y] = -1;
		}	
			
	}
	for (int i = 1; i <= n; ++i)
	if(q[i].size()&&deg[i]>mm){
		for (int j = 0; j < q[i].size(); ++j)
		ans[q[i][j].second] = dis[pos[i]][q[i][j].first];		
	}
	
	
	for(int i = 1; i <= Q; ++i)
	printf("%d\n",ans[i]);
	
	
	return 0;
}


