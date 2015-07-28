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

const int maxn=100001;
const int INF=199999999;

int n,m,k;
vector<int>G[1001];//route->point
vector<int>M[100001];//point->route
int d[maxn],pre[maxn];
int q[maxn],flag[maxn],flagr[1001];


void work(int x,int y)
{
	int i,j;
	for(i=0;i<maxn;++i)
	d[i]=INF;
	memset(pre,-1,sizeof(pre));
	
	int rear=-1,front=0;
	d[x]=0;
	q[++rear]=x;
	flag[x]=1;
	int cur,r,to;
	while(front<=rear)
	{
		cur=q[front++];
		for(i=0;i<M[cur].size();++i)
		{
			r=M[cur][i];
			if(flagr[r])continue;
			flagr[r]=1;
			for(j=0;j<G[r].size();++j)
			{
				to=G[r][j];
				if(flag[to])continue;
				flag[to]=1;
				d[to]=d[cur]+1;
				pre[to]=cur;
				q[++rear]=to;
				if(to==y){
					return;
				}								
			}			
		} 	
	}
}


int main()
{
	cin>>n>>m;
	int i,j,x,y;
	for(i=0;i<n;++i)
	{
		scanf("%d",&k);
		for(j=0;j<k;++j)
		{
			scanf("%d",&x); 
			G[i].push_back(x);
			M[x].push_back(i);
		}		
	}
	cin>>x>>y;//cout<<"EEE"<<endl;
	work(x,y);
	//cout<<"###"<<endl;
	int ans[maxn];
	if(d[y]==INF)cout<<"-1\n";
	else{
		cout<<d[y]<<endl;
		int ans[maxn],rear=-1;
		while(y!=x)
		{
			ans[++rear]=y;
			y=pre[y];
		}
		ans[++rear]=x;
		for(i=rear;i>0;--i)
		cout<<ans[i]<<' ';
		cout<<ans[i]<<endl;
		
		
	}
	
	
    return 0;
}

