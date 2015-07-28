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

LL c[21][21];
void init()
{
	c[0][0]=1;
	int i,j;
	for(i=1;i<=20;++i)
	for(j=0;j<=i;++j)
	{
		if(j==0)
		{
			c[i][j]=1;
			continue;
		}
		c[i][j]=c[i-1][j-1]+c[i-1][j];		
	}		 
}

LL f[21];

void work()
{
	int i,n,j;
	f[0]=f[1]=2;
	//f[2]=2;
	for(n=2;n<=20;++n)
	{
		for(j=1;j<=n;++j)
		{
			f[n]+=c[n-1][j-1]*f[j-1]/2*f[n-j]/2;
		} 		
	}
	f[0]=f[1]=1;
}


int main()
{
	init();
	int i;
	work();
	int n,x,k;
	cin>>n;
	while(n--)
	{
		cin>>x>>k;
		cout<<x<<' '<<f[k]<<endl; 
	}
	
    return 0;
}

