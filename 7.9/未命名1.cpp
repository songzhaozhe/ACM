#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<sstream> 
#define LL long long
using namespace std;

const int maxn=100010;
const int INF=199999999;

struct Ticket{
	int snum,fnum;
	
	void init(){snum=fnum=0;}
	int get(){return snum+fnum;}
};

map<string,int>M;
Ticket t[maxn][2];//0:single  1:family
int s,f;
int dp[maxn][2];
char buffer[maxn*10];
int first[maxn],next[maxn],rear,in[maxn],edgerear,u[maxn],v[maxn],q[maxn];

void init()
{
	M.clear();
	memset(in,0,sizeof(in));
	//memset(t,0,sizeof(t));
	memset(first,-1,sizeof(first));
	rear=edgerear=0;	
	memset(in,0,sizeof(in));
	//edgerear=0;	
}

int get(const string &s)
{
	map<string,int>::iterator t=M.find(s);
	if(t==M.end())
	return M[s]=++rear;
	else return M[s];
 } 

void addedge(int from,int to)
{
	next[++edgerear]=first[from];
	first[from]=edgerear;
	u[edgerear]=from;
	v[edgerear]=to;	
}

void dfs(int i)
{
	if(first[i]==-1)
	{
		dp[i][0]=s;
		t[i][0].snum=1;
		t[i][0].fnum=0;
		dp[i][1]=f;
		t[i][1].snum=0;
		t[i][1].fnum=1;		
	}
	int e;
//	dp[i][0]=dp[i][1]=0;
	t[i][0].fnum=t[i][1].snum=0;
	t[i][0].snum=t[i][1].fnum=1;
	dp[i][0]=s;
	dp[i][1]=f;
	for(e=first[i];e!=-1;e=next[e])
	{
		int &to=v[e];
	//	dfs(to);
		if(dp[to][0]<dp[to][1]||(dp[to][0]==dp[to][0]&&t[to][0].get()<t[to][1].get()))
		{
			dp[i][0]+=dp[to][0];
			t[i][0].snum+=t[to][0].snum;
			t[i][0].fnum+=t[to][0].fnum;		
		}
		else
		{
			dp[i][0]+=dp[to][1];
			t[i][0].snum+=t[to][1].snum;
			t[i][0].fnum+=t[to][1].fnum;
		}
		//family
		if(dp[to][0]-s<dp[to][1]||(dp[to][0]-s==dp[to][0]&&t[to][0].get()-1<t[to][1].get()))
		{
			dp[i][1]+=dp[to][0]-s;
			t[i][1].snum+=t[to][0].snum-1;
			t[i][1].fnum+=t[to][0].fnum;			
		}
		else
		{
			dp[i][1]+=dp[to][1];
			t[i][1].snum+=t[to][1].snum;
			t[i][1].fnum+=t[to][1].fnum;
		}	
	}
}


int main()
{
	gets(buffer);
	int cas=1;
	int i=1,fa,sn;
	char tmp[1002];
	while(buffer[0]!='0')
	{
		stringstream os(buffer);
		os>>s>>f;
		init();
		//cout<<s<<f<<endl;
		gets(buffer);
		while(!isdigit(buffer[0]))
		{
			stringstream os(buffer);
			os>>tmp;
			fa=get(tmp);
//cout<<"fa: "<<fa<<endl;
			while(os>>tmp)
			{
				sn=get(tmp);
//cout<<"sn: "<<sn<<endl;
				addedge(fa,sn);
				++in[sn];
			}
			gets(buffer);
		}
		for(i=1;i<=rear;++i)
		if(!in[i])addedge(0,i);
		int left=0,right=0;
		q[0]=0;
		
		while(left<=right)
		{
			int x=q[left++];
			for(int e=first[x];e!=-1;e=next[e])
			q[++right]=v[e];			
		}
		
		
		//cout<<"##"<<endl;
		int NS=0,NF=0,T=0;
		for(i=right;i>=0;--i)
		{
			//if(in[i])continue;
			dfs(i);
		//	cout<<"@@@@"<<i<<endl;
		
//cout<<dp[i][0]<<"  #  "<<dp[i][1]<<endl; 
		/*	if(dp[i][0]<dp[i][1]||(dp[i][0]==dp[i][1]&&t[i][0].get()<t[i][1].get())){
				NS+=t[i][0].snum;
				NF+=t[i][0].fnum;
				T+=dp[i][0];
			}
			else{
				NS+=t[i][1].snum;
				NF+=t[i][1].fnum;
				T+=dp[i][1];
			}
		}*/
		}
		printf("%d. %d %d %d\n",cas++,t[0][0].snum-1,t[0][0].fnum,dp[0][0]-s);
	//	cout<<cas++<<". "<<NS<<' '<<NF<<' '<<T<<'\n';
		
		
	}
	
	
    return 0;
}

