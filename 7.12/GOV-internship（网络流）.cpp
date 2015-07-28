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

const int maxn=2001000;
const int INF=199999999;

struct Edgelist{
	int rear;
	int v[maxn],first[maxn],next[maxn],flow[maxn];
	void clear(){
		rear=-1;
		memset(first,-1,sizeof(first));
	}
	void add(int from, int to, int f)
	{
		next[++rear]=first[from];
		first[from]=rear;
		v[rear]=to;
		flow[rear]=f;
		
		next[++rear]=first[to];
		first[to]=rear;
		v[rear]=from;
		flow[rear]=0;		
	}
}e;

int cur[maxn],d[maxn],vis[maxn];
int S,T;

bool BFS()
{
//	cout<<"!!!"<<endl;
	memset(d,-1,sizeof(d));
	int i;
	for(i=0;i<=T;++i)
	cur[i]=e.first[i];
	d[S]=1;
	int q[maxn],rear=-1,front=0;
	q[++rear] = S;
	while(front <= rear)
	{
		//cout<<"###"<<endl; 
		int x=q[front++];
		for(i = e.first[x]; i!=-1; i=e.next[i])
		if(e.flow[i]&&d[e.v[i]]==-1)
		{
			//cout<<"###"<<endl;
			q[++rear] = e.v[i];
			d[e.v[i]] = d[x] + 1;
		}//else cout<<"@@@"<<endl;
	}
	if(d[T]!=-1)return 1;
	else return 0;
}

int DFS(int x,int a)
{
//	cout<<"##DFS#"<<endl;
	if(x == T || a == 0)return a;
	int ans=0,f;
	for(int &i = cur[x]; i != -1; i = e.next[i])
	{
		int to = e.v[i];
		if(d[to]==d[x]+1 && (f=DFS(to,min(a,e.flow[i]))))
		{
			ans+=f;
			a-=f;
			e.flow[i]-=f;
			e.flow[i^1]+=f;
			if(a == 0)break;
		}
	}
	return ans;
}


char s[maxn],p[maxn];
int main()
{
	int sum=0;
	scanf("%s%s",&s,&p);
	int lens=strlen(s),lenp=strlen(p);
	int i,j;
	S=lens + lenp + 2;
	T=lens + lenp + 3;
	int cnt1[1002]={0},cnt0[1002]={0};
	e.clear();
	for(j = 0; j < lenp; ++j)
	{
		if(p[j] == '?')
		{
			int c1=0,c0=0;
			for(i = j; i <= lens - lenp + j; ++i)
			{
				if(s[i]=='?'){
					e.add(i,j + lens, 1);
					e.add(j + lens, i, 1);
				}
				if(s[i] == '0')c0++;
				if(s[i] == '1')c1++;
			}
			e.add(S,lens+j,c0);
			e.add(lens+j,T,c1);
		}
		if(p[j]=='1')
		{
			for(i = j; i <= lens - lenp + j; ++i)
			{
				if(s[i]=='?')cnt1[i]++;
				if(s[i]=='0')sum++;
			}			
		}
		if(p[j]=='0')
		{
			for(i = j; i <= lens - lenp + j; ++i)
			{
				if(s[i]=='?')cnt0[i]++;
				if(s[i]=='1')sum++;
			}
		}		
	} 
	for(i=0;i<lens;++i)
	if(s[i]=='?')
	{
		e.add(S,i,cnt0[i]);
		e.add(i,T,cnt1[i]);
	}
	while(BFS())
	sum+=DFS(S,INF);
	
	for(i=0;i<lens;++i)
	if(s[i]=='?'){
		if(d[i]!=-1)s[i]='0';
		else s[i]='1';
	}
	for(i=0;i<lenp;++i)
	if(p[i]=='?'){
		if(d[lens+i]!=-1)p[i]='0';
		else p[i]='1';
	}
	
	
	cout<<sum<<endl;
	cout<<s<<endl;
	cout<<p<<endl;
	
	
	
	
    return 0;
}

