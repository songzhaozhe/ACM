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

const int maxn=20010;
const int INF=199999999;

bool flag[21];
int a[21];
LL ans;

void dfs(int n,int alr)
{
	if(alr==n){
		//for(int i=1;i<=alr;++i)	cout<<a[i]<<' ';	cout<<endl;		
		++ans;
		return;
	} 
	
//	memset(flag,0,sizeof(flag));	
	int i;
	//for(i=1;i<=alr;++i)
//	flag[a[i]]=1; 
		//down
	if(a[alr-1]<a[alr])
	{
		for(i=1;i<a[alr];++i)
		if(!flag[i])
		{
			a[alr+1]=i;
			flag[i]=1;
			dfs(n,alr+1);
			flag[i]=0;
		}		
	}
	//up
	if(a[alr-1]>a[alr])
	{
		for(i=a[alr]+1;i<=n;++i)
		if(!flag[i])
		{
			a[alr+1]=i;
			flag[i]=1;
			dfs(n,alr+1);
			flag[i]=0;
		} 
	}
	
	
}

int main()
{
	int i,n;
	for(n=1;n<=10;++n){
	ans=0;
	a[0]=0;
	for(i=1;i<=n;++i) 
	{
		a[1]=i;
		flag[i]=1;
		dfs(n,1);
		flag[i]=0;
	}
	a[0]=100;
	for(i=1;i<=n;++i) 
	{
		a[1]=i;
		flag[i]=1;
		dfs(n,1);
		flag[i]=0;
	}
	cout<<n<<' '<<ans<<endl;
	}
    return 0;
}

