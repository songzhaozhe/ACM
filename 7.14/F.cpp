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

int b[maxn];
int cnt[31];
int ans[31];
int num[maxn]={0};


int main()
{
	int n,m;
	cin>>m;
	int i,j;
	for(i=1;i<=m;++i)
	scanf("%d",&b[i]);
	n=(1+(int)sqrt(2+8*m))/2;
	
	for(i=0;i<=30;++i)
	{
		for(j=1;j<=m;++j)
		cnt[i]+=((b[j]>>i)&1);
		ans[i]=n-(n+(int)sqrt(n*n-4*cnt[i]+1))/2;
	}
	
	for(i=0;i<=30;++i)
	{
		for(j=1;j<=ans[i];++j)
		num[j]=num[j]^(1<<i);
	}
	for(i=1;i<n;++i)
	printf("%d ",num[i]);
	printf("%d\n",num[i]);
	
    return 0;
}

