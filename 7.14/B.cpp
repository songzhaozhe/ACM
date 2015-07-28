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
#define LL long long
using namespace std;

const int maxn=400100;
const int INF=199999999;
struct pii{
	int first,second,num;
};

int n;
char s[maxn];
vector<pii>G[maxn];
int need[maxn]={0},add[maxn]={0},ans=0,q[maxn],rear=-1;



int dfs(int cur,int fa)
{
	if(G[cur].size()==1&&fa!=-1){
		need[cur]=0;
		return 0;
	}
	int i,j,x,maxx=0;
	pii y;
	for(i=0;i<G[cur].size();++i)
	{
		y=G[cur][i];
		if(y.first==fa)continue;
		if(y.second==0){
			maxx=max(maxx,dfs(y.first,cur)+1);
		}
		else{
			maxx=max(maxx,dfs(y.first,cur)-1); 
		}	
	}
	need[cur]=maxx;
	return maxx;
}
int dfs2(int cur,int fa)
{
	int i,j,x,maxx=0,ans=0;
	if(add[cur]>=need[cur])return 0;
	
	pii y;
	for(i=0;i<G[cur].size();++i)
	{
		y=G[cur][i];
		if(y.first==fa)continue;
		add[y.first]=add[cur];
		if(y.second==0)
		{
			if(need[y.first]+1>add[cur])
			{
				//cout<<"###\n"<<endl;
			q[++rear]=y.num;
			add[y.first]+=1;
			++ans;
			ans+=dfs2(y.first,cur);	
			}
		}
		else 
		{
			add[y.first]++;
			ans+=dfs2(y.first,cur);
		}
		
		//ans+=dfs2(y.first,cur);
	}
	return ans;
}



int main()
{
	cin>>n;
	int x,y;
	int i,j;
//	G.clear();
	for(i=1;i<=n-1;++i)
	{	
		scanf("%d%d",&x,&y);
		gets(s);
		if(s[1]=='a'){
			G[x].push_back((pii){y,0,i});
			G[y].push_back((pii){x,0,i});			
		}
		else {
			G[x].push_back((pii){y,1,i});
			G[y].push_back((pii){x,1,i});		
		}
	}
	dfs(1,-1);
	//for(i=1;i<=n;++i)
//	cout<<need[i]<<' '<<endl;
	int ddd=dfs2(1,-1);
	cout<<ddd<<endl;
	sort(q,q+rear+1);
	for(i=0;i<rear;++i)
	printf("%d ",q[i]);
	if(ddd!=0)printf("%d\n",q[i]);
	
	
    return 0;
}

