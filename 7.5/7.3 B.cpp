#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
using namespace std;

const int maxn=86400;
const int MAXN=2010;
const int INF=199999999;

int n,k,l[MAXN],r[MAXN],ww[MAXN];
int flag[maxn],rear=0,point[maxn];
int first[maxn],next[maxn],u[maxn],v[maxn],flow[maxn],cost[maxn],cap[maxn];

void addedge(int from,int to,int captmp,int costtmp)
{
	static int r=-1;
	next[++r]=first[from];
	first[from]=r;
	u[r]=from;v[r]=to;
	cost[r]=costtmp;
	cap[r]=captmp;
	flow[r]=0;
	
	next[++r]=first[to];
	first[to]=r;
	u[r]=to;v[r]=from;
	cost[r]=-costtmp;
	cap[r]=0;
	flow[r]=0;	
}

void makegraph()
{
	memset(first,-1,sizeof(first));
	int i;
	for(i=0;i<=rear;++i)
	addedge(i,i+1,k,0);
	
	for(i=1;i<=n;++i)
	{
		addedge(point[l[i]],point[r[i]],1,-ww[i]);
	}
	
}
int inq[maxn],d[maxn],p[maxn],a[maxn];
bool BellmanFord(int s,int t,int &bbflow,int &bbcost){
	for(int i=0;i<=n;++i)d[i]=INF;
	memset(inq,0,sizeof(inq));
	d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
	
	queue<int>Q;
	Q.push(s);
	while(!Q.empty()){
		int from=Q.front();Q.pop();
	//	cout<<"@@@"<<from<<endl;
		inq[from]=0;
		int e;
		for(e=first[from];e!=-1;e=next[e]){
			if(cap[e]>flow[e]&& (d[v[e]]>d[from]+cost[e])){
				d[v[e]]=d[from]+cost[e];
				p[v[e]]=e;
				a[v[e]]=min(a[from],cap[e]-flow[e]);
				if(!inq[v[e]]){
					Q.push(v[e]);
					inq[v[e]]=1;
				}				
			}			
		}		
	}
	if(d[t]==INF)return 0;
	bbflow+=a[t];
	bbcost+=d[t]*a[t];
	int from=t;
	while(from!=s){
		flow[p[from]]+=a[t];
		flow[p[from]^1]-=a[t];
		from=u[p[from]];	
	}
	return 1;	
}


int Mincost(int s,int t){
	int flow=0,cost=0;
	n=rear+1;
	while(BellmanFord(s,t,flow,cost));
	return cost;	
}

int main()
{
	cin>>n>>k;
	int i,j,x,y,z;
	char ch1,ch2;
	for(i=1;i<=n;++i)
	{
		scanf("%d%c%d%c%d",&x,&ch1,&y,&ch2,&z);
		//cout<<x<<' '<<y<<' '<<z<<endl;
		l[i]=x*3600+y*60+z;
		flag[l[i]]=1;
		scanf("%d%c%d%c%d",&x,&ch1,&y,&ch2,&z);
		//cout<<x<<' '<<y<<' '<<z<<endl;
		r[i]=x*3600+y*60+z;
		flag[r[i]]=1;
		scanf("%d",&ww[i]);
	//	cout<<l[i]<<' '<<r[i]<<' '<<ww[i]<<endl;
	}
	for(i=0;i<maxn;++i)
	{
		if(flag[i]){
			point[i]=++rear;
		}
	}
	makegraph();
	
	cout<<(-1)*Mincost(0,rear+1)<<endl;
	
	
	
	
    return 0;
}

