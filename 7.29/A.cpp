#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=20010;
const int INF=199999999;

int n,m;
vector<int> G[maxn];

void add(int a,int b)
{
	G[a].push_back(b);
	G[b].push_back(a);
}

int q[maxn],d[maxn],fa[maxn];

int BFS(int s)
{
	memset(d,-1,sizeof(d));
	int front=0,rear=-1;
	fa[s]=-1;
	q[++rear]=s;
	int minn=INF;
	d[s]=0;
	while(front <= rear)
	{
		int x = q[front++];
	//	cout<<"###"<<x<<' '<< d[x] <<endl;
		for (int i = 0; i < G[x].size(); ++i)
		{
			int y = G[x][i];
			if (y != fa[x]) {
				if ( d[y] == -1)
				{
					q[++rear] = y;
					fa[y] = x;
					d[y] = d[x] + 1;
				} else {
				//	cout<<"@@@@@@@@@@@@@"<<endl;
					minn = min (minn, d[x] + d[y] + 1);
				}				
			}
		}
	}
	return minn;
}



int main()
{
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; ++cas)
	{
		scanf("%d%d",&n,&m);
		int x,y;
		for(int i = 0; i < n; ++i)
		G[i].clear();
		for(int i = 1; i <= m; ++i)
		{
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		int minn=INF;
		for(int i = 0; i < n; ++i)
		{
			minn = min(minn, BFS(i));
		}
		printf("Case %d: ",cas);
		if(minn == INF){
			printf("impossible\n");
		}
		else{
			printf("%d\n",minn);
		}
		
	}
	 
    return 0;
}

