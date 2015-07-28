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

const int maxn=3001;
const int INF=199999999;

int T,n,a[maxn],maxx=0,f[maxn],N;
vector<int>In[maxn];

struct Edge{
	int from,to,cap,flow;
};
vector<int>G[maxn];
vector<Edge>edges;

void AddEdge(int from,int to,int cap){
	edges.push_back((Edge){from,to,cap,0});
	edges.push_back((Edge){to,from,0,0});
	int m=edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
}

void dp()
{
	//cout<<"###"<<endl;
	memset(f,0,sizeof(f)); 
	int i,j;
	f[0]=-1;
	for(i=1;i<=N;++i)
	{
		int tmp=0;
		for(j=1;j<i;++j)
		if(a[i]>a[j])tmp=max(tmp,f[j]);
		for(j=1;j<i;++j)
		if(a[i]>a[j]&&f[j]==tmp)In[i].push_back(j);
		f[i]=tmp+1;
		//cout<<f[i]<<' ';
		maxx=max(maxx,f[i]);	
	}	
}
int extra;

void construct()
{
	int i;
	extra=N+2;
	int q[maxn],left=0,right=-1,vis[maxn]={0};
	for(i=1;i<=N;++i)
	if(f[i]==maxx){
		q[++right]=i;
		AddEdge(i+extra,i,1);
		AddEdge(i,N+1,1);
//cout<<i<<' '<<n+1<<endl;
		vis[i]=1;		
	}
	while(left<=right)
	{
		int x=q[left++];
		if(In[x].size()==0){
			AddEdge(0,x+extra,1);
		//	AddEdge(x+extra,x,1);
//cout<<x<<endl;
			continue;
		}		
		for(int j=0;j<In[x].size();++j) 
		{
			int y=In[x][j];
			AddEdge(y,x+extra,1);
			if(!vis[y])
			AddEdge(y+extra,y,1);
			if(!vis[y]){vis[y]=1;q[++right]=y;}			
		}		
	}
//	cout<<right<<"###"<<endl;
	n=(right+1)*2+2;
//	cout<<n<<endl;
}
int p[maxn],num[maxn],cur[maxn],d[maxn];

int Augment(int s,int t){
	int x=t,a=INF;
//	cout<<s<<' '<<t<<endl;
	while(x!=s){
		Edge &e=edges[p[x]];
		a=min(a,e.cap-e.flow);
		x=edges[p[x]].from;
	}
	x=t;
	while(x!=s){
		edges[p[x]].flow+=a;
		edges[p[x]^1].flow-=a;
		x=edges[p[x]].from;
	}
	return a;	
}

int Maxflow(int s,int t){
//	this->s=s;this->t=t;
	int flow=0;
	memset(num,0,sizeof(num));
	memset(d,0,sizeof(d));
	for(int i=0;i<n;++i)num[d[i]]++;
	int x=s;
	memset(cur,0,sizeof(cur));
	while(d[s]<n){
		if(x==t){
			flow+=Augment(s,t);
			x=s;
		}
		int ok=0;
		for(int i=cur[x];i<G[x].size();++i){
			Edge &e=edges[G[x][i]];
			if(e.cap>e.flow&&d[x]==d[e.to]+1){
				ok=1;
				p[e.to]=G[x][i];
				cur[x]=i;
				x=e.to;
				break;
			}			
		}
		if(!ok){
			int m=n-1;
			for(int i=0;i<G[x].size();++i){
				Edge &e=edges[G[x][i]];
				if(e.cap>e.flow)m=min(m,d[e.to]);
			}
			if(--num[d[x]]==0)break;
			num[d[x]=m+1]++;
			cur[x]=0;
			if(x!=s)x=edges[p[x]].from;			
		}		
	}
	return flow;
}

int main()
{
	cin>>T;
	while(T--)
	{
		maxx=0;
		for(int i=0;i<maxn;++i)
		In[i].clear(),G[i].clear();
		edges.clear();
		cin>>N;
		for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
		dp();
		construct();
		cout<<Maxflow(0,N+1)<<endl;		
	}
	
	
    return 0;
}

/*
1
6
1 2 4 3 6 2


*/

