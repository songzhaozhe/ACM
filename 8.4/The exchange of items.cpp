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
const int maxn=8e4+100;
const int INF = 2e9;

struct Edgelist{
	int first[maxn],next[maxn],flow[maxn],cost[maxn],u[maxn],v[maxn];
	int rear;
	void init(){
		rear = -1;
		memset(first,-1,sizeof(first));
	}
	void add(int from,int to,int f,int w){
		next[++rear] = first[from];
		first[from] = rear;
		u[rear] = from;
		v[rear] = to;
		flow[rear] = f;
		cost[rear] = w;
		
		next[++rear] = first[to];
		first[to] = rear;
		u[rear] = to;
		v[rear] = from;
		flow[rear] = 0;
		cost[rear] = -w;		
	}
	
}e;

int pre[maxn],vis[maxn],q[maxn],dis[maxn],f[maxn];

int SPFA(int s, int t){
	for (int i = 0; i < t+5; ++i)
	{dis[i] = INF;pre[i] = -1; vis[i] = 0;}
	int rear = -1, front = 0;
	q[++rear] = s;
	vis[s] = 1;
	pre[s] = -1;
	dis[s] = 0;
	f[s] = INF;
	while(front <= rear)
	{
		int x = q[front++];
		vis[x] = 0;
		for (int j = e.first[x]; j != -1; j = e.next[j])
		{
			int y = e.v[j];
			if (e.flow[j] > 0 && dis[x] + e.cost[j] < dis[y])
			{
				pre[y] = j;
				dis[y] = dis[x] + e.cost[j];
				f[y] = min(f[x],e.flow[j]);
				if(!vis[y]){
					q[++rear] = y;
					vis[y] = 1;
				}				
			}
		}
	}
	
	if(dis[t]!=INF)return f[t];
	else return 0;
	
	
}

int augment(int s,int t,int f){
	int u = pre[t];
	int ans = 0;
	while (u != -1){
		e.flow[u]-=f;
		e.flow[u^1]+=f;	
		u = pre[e.u[u]];
	}
	return f * dis[t];
}
int maxflow;
int Mincost(int s, int t){
	int ans = 0;
	int tmp;
	while(tmp = SPFA(s,t)){
	//	cout<<tmp<<endl;
		maxflow += tmp;
		ans+=augment(s,t,tmp);
	}
	return ans;
	
}


int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int a,b;
		int tot1 = 0, tot2 = 0;
		e.init();
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d",&a,&b);
			if (a>b){
				e.add(0,i,a-b,0);
				tot1 += a-b;
			}
			else if(a<b){
				e.add(i,n+1,b-a,0);
				tot2 += b-a;
			}		
		}

		for (int i = 1; i <= m; ++i)
		{
			scanf("%d%d",&a,&b);
			e.add(a,b,INF,1);
			e.add(b,a,INF,1);
		}
//		if(tot1!=tot2){
//			puts("-1");
//			continue;
//		}
		maxflow = 0;
		int ans = Mincost(0,n+1);
		if (maxflow < tot2)printf("-1\n");
		else printf("%d\n",ans);
		
	}
	
	return 0;
}


