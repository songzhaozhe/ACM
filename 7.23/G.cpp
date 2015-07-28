#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=20020;
const int INF=199999999;
typedef long long LL;

vector<int> edge[maxn];
vector<vector<int> >connect;
int dfn[maxn],low[maxn],in_seq[maxn];
int stack[maxn],list[maxn];
int cnt,top,pop,len,del[maxn];
int fa[maxn],tot[maxn];

void biconnect(int v){
	stack[++top]=v;
	dfn[v]=low[v]=pop++;
	int i,succ;
	for(i=edge[v].size()-1;i>=0;i--){
		succ=edge[v][i];
		if(dfn[succ]==-1){
			biconnect(succ);
			if(low[succ]>=dfn[v]){
				cnt++;
				len=0;
				do{
					in_seq[stack[top]]-cnt;
					list[len++]=stack[top];
					top--;
				}while(stack[top+1]!=succ);
				in_seq[v]=cnt;
				list[len++]=v;
				vector<int>tmp(list,list+len);
				connect.push_back(tmp);
			}
			low[v]=min(low[v],low[succ]);
		}else low[v]=min(low[v],dfn[succ]);
	}
}

int find(int x)
{
	return fa[x]==0?x:fa[x]=find(fa[x]);
}

int solve()
{
	connect.clear();
	for(int i=0;i<maxn;++i)
	edge[i].clear();
	memset(dfn,-1,sizeof(dfn));
	memset(del,0,sizeof(del));
	memset(low,0,sizeof(low));
	memset(fa,0,sizeof(fa));
	memset(tot,0,sizeof(tot));
	pop=0;
	cnt=0;
	top=0;
	len=0;	
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j,x,y;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(i=1;i<=n;++i)
	if(dfn[i]==-1)biconnect(i);
	
	for(i=0;i<connect.size();++i){
	if(connect[i].size()<=2)continue;
	for(j=0;j<connect[i].size();++j)
	{
		del[connect[i][j]]=1;
		//cout<<connect[i][j]<<' ';
	}//cout<<endl;}
}
	
	for(i=1;i<=n;++i)
	{
		if(del[i])continue;
		for(j=0;j<edge[i].size();++j)
		{
			if(del[edge[i][j]])continue;
			x=find(i);
			y=find(edge[i][j]);
			if(x!=y)fa[y]=x;
		}
	}
	for(i=1;i<=n;++i)
	tot[find(i)]++;
	int ans=0;
	for(i=1;i<=n;++i)
	{
		//cout<<tot[i]<<endl;
		ans+=(LL)tot[i]*(tot[i]-1)/2;
	}
	return ans;
}
			

int main()
{
	int T;
	scanf("%d",&T);
	int cas=1;
	for(;cas<=T;++cas)
	{
		printf("Case #%d: %d\n",cas,solve());
	}	
    return 0;
}
/*
 4 7 6 1 2 1 3 2 4 3 4 4 5 5 6 5 4 1 2 2 3 2 4 4 5 4 4 1 2 2 3 3 4 4 1 8 8 1 2 2 3 2 4 2 5 3 4 5 6 6 7 6 8  
 */
