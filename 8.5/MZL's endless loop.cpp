#pragma comment(linker, "/STACK:10240000000,10240000000")
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
//#define eid first
//#define vtx second
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn = 2e5+100;
const int maxm = 1e6+10;

typedef pair<int,int> pii;
vector<pii> adj[maxn];
vector<pii>G;

int father[maxn];
bool vis[maxm];

int getFather(int x){
	return x == father[x]?x:father[x] = getFather(father[x]);
}

void add(int x,int y,int z)
{
	adj[x].push_back(make_pair(z,y));
	adj[y].push_back(make_pair(z,x));	
}
vector<int>path;



void dfs(int u){
	for (int it = 0; it < adj[u].size(); ++it)
	if(!vis[adj[u][it].first]){
		vis[adj[u][it].first] = true;
		dfs(adj[u][it].second);
		path.push_back(adj[u][it].first);
	}
}



bool solve()
{
	for (int i = 0; i < maxn; ++i)father[i] = i;
	for (int i = 0; i < maxn; ++i){
		for (int j = 0; j < adj[i].size(); ++j){
			father[getFather(i)] = getFather(adj[i][j].second);
		}
	}
	int origin = -1;
	for (int i = 0; i < maxn; ++i)if(adj[i].size()){
		if(adj[i].size()%2==1)return 0;
		if(origin==-1)origin = i;
		if(getFather(i)!=getFather(origin))return 0;
		sort(adj[i].begin(),adj[i].end());
	}
	
	path.clear();
	memset(vis,false,sizeof(vis));
	if(!origin!=-1)dfs(origin);
	reverse(path.begin(),path.end());
}

int deg[maxn],n,m,ans[maxn];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y;
		G.clear();
		scanf("%d%d",&n,&m);
		memset(deg,0,sizeof(deg));
		vector<int>odd;
		G.push_back(make_pair(0,0));
		for(int i = 1; i <=n; ++i)adj[i].clear();
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d%d",&x,&y);
			add(x,y,i);
			G.push_back(make_pair(x,y));
			deg[x]++;
			deg[y]++;
		}
		for (int i = 1; i <= n; ++i)
		if(deg[i]%2==1)odd.push_back(i);
		for (int i = 0; i < odd.size(); i+=2)
		{add(odd[i],odd[i+1],m+i/2+1);G.push_back(make_pair(odd[i],odd[i+1]));}//printf("Add: %d %d\n",odd[i],odd[i+1]);}
		
		solve();
		int u;
		if(G[path[0]].first==G[path[1]].second)u = G[path[0]].first;
		if(G[path[0]].first==G[path[1]].first)u = G[path[0]].first;		
		if(G[path[0]].second==G[path[1]].second)u = G[path[0]].second;		
		if(G[path[0]].second==G[path[1]].first)u = G[path[0]].second;		
		//u= G[path[0]].first;
		ans[path[0]] = 1;
		//cout<<path[0]<<"###"<<G[path[0]].first<<' '<<G[path[0]].second<<endl;
		for (int i = 1; i < path.size(); ++i)
		{
			//cout<<"@@@"<<u<<endl;
		//	printf("%d####%d %d\n",path[i],G[path[i]].first,G[path[i]].second);
			if(G[path[i]].first==u){
				u = G[path[i]].second;
				ans[path[i]] = 1;
				continue;
			}
			if(G[path[i]].second==u){
				u = G[path[i]].first;
				ans[path[i]] = 0;
				continue;
			}					
		}
		for(int i = 1; i <=m; ++i)
		printf("%d\n",ans[i]);
		
	}
		
	
	return 0;
}


