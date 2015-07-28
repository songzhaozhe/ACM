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

int a[6],sum=0,maxx=0,minn=INF; 


int main()
{
	int i;
	for(i=0;i<6;++i)
	{
		scanf("%d",&a[i]);
		maxx=max(a[i],maxx);
		minn=min(minn,a[i]);
		sum+=a[i];
	}
	
	while(!(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0))
	{
		
		double ans=1.0*(sum-maxx-minn)/4;
		cout<<ans<<'\n';
		sum=0;
		maxx=0;
		minn=INF;
		for(i=0;i<6;++i)
	{
		scanf("%d",&a[i]);
		maxx=max(a[i],maxx);
		minn=min(minn,a[i]);
		sum+=a[i];
	}
		
		
	}
	
	
    return 0;
}

