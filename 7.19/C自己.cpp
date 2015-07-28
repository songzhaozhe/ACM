#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
//#include<cmath>
#include<map>
#include<queue>
#include<vector>
#define LL long long
using namespace std;

const int maxn=200;
const int INF=199999999;

inline lowbit(int x){return x&(-x);}
 
LL s[maxn][maxn][maxn]={0};

int n,x1,x2,y1,y2,z1,z2;
LL k;

void add()
{
	int x,y,z;
	for(x=x1;x<=n;x+=lowbit(x))
	for(y=y1;y<=n;y+=lowbit(y))
	for(z=z1;z<=n;z+=lowbit(z))
	{
		s[x][y][z]+=k;
	}
	
	return;
}

LL sum(int x,int y,int z)
{
	long long ret=0;
	for(int i=x;i>0;i-=lowbit(i))
	for(int j=y;j>0;j-=lowbit(j))
	for(int k=z;k>0;k-=lowbit(k))
	ret+=s[i][j][k];
	
	return ret;
}
	


int main()
{
	scanf("%d",&n);
	int m;

	while(1)
	{
		scanf("%d",&m);
		if(m==3)break;
		if(m==1)
		{
			scanf("%d%d%d%lld",&x1,&y1,&z1,&k);
			x1++;y1++;z1++;
			add();
		}
		else
		{
			scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
			x1++;y1++;z1++;x2++;y2++;z2++;			
			LL ans=0;
			ans+=sum(x2,y2,z2);
			ans-=sum(x1-1,y2,z2);
			ans-=sum(x2,y1-1,z2);
			ans-=sum(x2,y2,z1-1);
			ans+=sum(x1-1,y1-1,z2);
			ans+=sum(x1-1,y2,z1-1);
			ans+=sum(x2,y1-1,z1-1);
			ans-=sum(x1-1,y1-1,z1-1);
			printf("%lld\n",ans);
			
			
		}
	}
	
    return 0;
}

