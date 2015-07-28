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

const int maxn=1010;
const int INF=199999999;

int flag[maxn],alr[260][260][260];
int x,y,z;

void update(int a,int b,int c)
{
	flag[a]=flag[b]=flag[c]=1;
	flag[a+b]=flag[b+c]=flag[a+c]=1;
	flag[a+b+c]=1;
	
	
} 

void dfs(int a,int b,int c)
{
	if(alr[a][b][c])return;	
	alr[a][b][c]=1;
	update(a,b,c);
	if(a==x&&b==y&&c==z)return;
	int t;
	if(a!=x)dfs(x,b,c);
	if(b!=y)dfs(a,y,c);
	if(c!=z)dfs(a,b,z);
	
	if(a>0){
		t=y-b;
		if(a>t)dfs(a-t,y,c);
		else dfs(0,b+a,c);
		
		t=z-c;
		if(a>t)dfs(a-t,b,z);
		else dfs(0,b,c+a);		
	} 
	if(b>0){
		t=x-a;//b->a
		if(b>t)dfs(x,b-t,c);
		else dfs(a+b,0,c);
		t=z-c;//b->c
		if(b>t)dfs(a,b-t,z);
		else dfs(a,0,c+b);		
	}
	if(c>0){
		t=x-a;//c->a
		if(c>t)dfs(x,b,c-t);
		else dfs(a+c,b,0);
		t=y-b;//c->b
		if(c>t)dfs(a,y,c-t);
		else dfs(a,b+c,0);		
	}
	
	
}


int main()
{
	cin>>x>>y>>z;
	//flag[1]=flag[1]=flag[2]=1;
	dfs(0,0,0);
	int i,ans=0;
	for(i=1;i<maxn;++i)
	if(flag[i])++ans;
	cout<<ans<<endl;
	
	
    return 0;
}

