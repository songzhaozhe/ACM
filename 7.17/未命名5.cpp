#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#define LL long long
using namespace std;

const int maxn=100010;
const int INF=199999999;

int T;
int n,m;
int first[500],next[maxn],u[maxn],v[maxn],edgerear=-1,in[maxn],vis[500],q[500],rear,pos[500];
void addedge(int from,int to){
	next[++edgerear]=first[from];
	first[from]=edgerear;
	v[edgerear]=to;
	

}



void TOPO()
{

//	sort(con,con+cnt+1);
	int flag[500]={0},i,x;
	priority_queue<int>PQ;
	
	for(i=1;i<=n;++i)
	{
		if(in[i]==0){
			PQ.push(i);
			flag[i]=1;
			//pos[con[i]]=rear;
		}
	}
	//if(rear==tmp)return -1;

	while(!PQ.empty())
	{
		x=PQ.top();
		PQ.pop();
		q[--rear]=x;
		pos[x]=rear;
		for(int e=first[x];e!=-1;e=next[e])
		{
			int y=v[e];
			if(flag[y])continue;
			--in[y];
			if(in[y]==0){
				PQ.push(y);
				flag[y]=1;
			}
		}
	}
}


int main()
{
	cin>>T;
	int i,j,x,y;
	while(T--)
	{
		memset(first,-1,sizeof(first));
		rear=0;
		edgerear=-1;
		memset(in,0,sizeof(in));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		rear=n+1;
		for(i=1;i<=m;++i)
		{
			scanf("%d%d",&x,&y);
			addedge(y,x);
			in[x]++;
		}
		TOPO();
		if(rear!=1){
			printf("-1\n");
			continue;
		}
		for(i=1;i<n;++i)
		printf("%d ",pos[i]);
		printf("%d\n",pos[i]);
	}
		
		
	
	
    return 0;
}

