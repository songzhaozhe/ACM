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
const int maxn=6e5+100;
const int N = 1e5+100;

struct Edgelist{
	int next[maxn],first[N],u[maxn],v[maxn],num[maxn];
	int rear;
	void init(){
		rear = -1;
		memset(first,-1,sizeof(first));
	}
	void add(int from, int to, int n){
		next[++rear] = first[from];
		first[from] = rear;
		u[rear] = from;
		v[rear] = to;
		num[rear] = n;
		
		next[++rear] = first[to];
		first[to] = rear;
		u[rear] = to;
		v[rear] = from;
		num[rear] = n;		
	}	
}e;

int ans[maxn];
int vis[N],flag[maxn],pre[N];
int n,m;

void dfs(int x)
{
	
	
}

int main()
{
	scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d%d",&n,&m);
		e.init();
		memset(ans,-1,sizeof(ans));
		memset(pre,-1,sizeof(pre));
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d%d",&x,&y);
			e.add(x,y);
		}
		for (int i = 1; i <= n; ++i)
		if(!vis[i])dfs(i);
		
		
	}
	
	
	return 0;
}


