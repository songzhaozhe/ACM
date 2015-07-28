#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=200010;
const int INF=199999999;

int n;

struct Edge{
	int from,to,dist;
};

vector<Edge>edges;
vector<int>G[maxn];
int val[maxn],flag[maxn];


void AddEdge(int from,int to,int dist)
{
	edges.push_back((Edge){from,to,dist});
	int m=edges.size();
	G[from].push_back(m-1);
 } 

void dfs(int i)
{
	if(flag[i])return;
	flag[i]=1;
	int j;
	Edge e;
	for(j=0;j<G[i].size();++j)
	{
		e=edges[G[i][j]];
		val[e.to]=val[i]^e.dist;
		dfs(e.to);		
	 }
	 return;	
}

int tmpmax,maxx=0;
int ch[3200000][2],num=1,w[3200000];

void insert(int v)
{
	tmpmax=0;
	int pos=1<<30;
	int i,u=0,mirror=0;
	while(pos>0)
	{
		int c=pos&v;
	//	pos>>=1;
		if(!ch[u][c]){
			ch[u][c]=num++;						
		}
		if(ch[mirror][c^1])mirror=ch[mirror][c^1];
		else mirror=ch[mirror][c];
		u=ch[u][c];		
		pos>>=1;		
	}
	w[u]=v;
	maxx=max(maxx,w[mirror]);
}


int main()
{
	cin>>n;
	int x,y,z;
	int i;
	for(i=1;i<n;++i) 
	{
		scanf("%d%d%d",&x,&y,&z);
		AddEdge(x,y,z);
		AddEdge(y,x,z);
	}
	val[0]=0;
	Edge e;
	flag[0]=1;
	for(i=0;i<G[0].size();++i)
	{
		e=edges[G[0][i]];
		val[e.to]=e.dist;
		dfs(e.to);
	}
	
	
	for(i=0;i<n;++i)
	insert(val[i]);
	
	cout<<maxx<<endl;
	
	
	
    return 0;
}

