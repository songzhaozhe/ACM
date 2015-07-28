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

const int maxn=1000010;
const int maxp=1000010;

int vis[maxn],ok[maxn],s1[maxn],s2[maxn];

void sieve()
{
	vis[0]=1;
	vis[1]=1;
	int n=maxp;
	int m=(int)sqrt(n+0.5);
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=m;++i)if(!vis[i])
	for(int j=i*i;j<=n;j+=i)vis[j]=1; 
}



int main()
{
	sieve();
	//for(int i=1;i<=20;++i)
//	cout<<i<<' '<<vis[i]<<endl;
	int i,j,ii,L,U;
	for(i=1;i<=1000;++i)
	{
		ii=i*i;
		for(j=i+1;j<=sqrt(maxp-ii);++j)
		{
			ok[ii+j*j]=1;
		}		
	}
	
	s2[1]=0;
	s1[0]=0;
	s1[1]=0;
	s2[2]=1;
	s1[2]=1;
	for(i=3;i<maxp;++i)
	{
		s2[i]=s2[i-1];
		s1[i]=s1[i-1];
		if(!vis[i]){++s1[i];
		if(ok[i])++s2[i];}
	}
	scanf("%d%d",&L,&U);
	while(!(L==-1&&U==-1))
	{
		if(U<=0)
			printf("%d %d %d %d\n",L,U,0,0);
		else if(L<=0)
		printf("%d %d %d %d\n",L,U,s1[U],s2[U]);
		else
		printf("%d %d %d %d\n",L,U,s1[U]-s1[L-1],s2[U]-s2[L-1]);
		
		scanf("%d%d",&L,&U);
		
	}
	
	
	
	
    return 0;
}

