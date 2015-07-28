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

const int maxn=510;
const int INF=199999999;

struct node{
	int x;
	int y;
}ans[maxn];

int f[maxn][maxn][maxn];
int m1,m2;
int a1[maxn],a2[maxn];

int find(int a[],int k)
{
	int l=0,r=maxn-1;
	while(l<r-1)
	{
		int mid=(r-l)/2+l;
		if(a[mid]<k)l=mid;
		else r=mid;
	}
	return r;
}

int maxx=0;
int main()
{
	cin>>m1;
	int i,j,k;
	for(i=0;i<maxn;++i)
	a1[i]=a2[i]=INF;
	for(i=1;i<=m1;++i)
	scanf("%d",&a1[i]);
	cin>>m2;
	for(i=1;i<=m2;++i)
	scanf("%d",&a2[i]);	
	
	
	f[0][0][0]=0;
	for(i=1;i<=max(m1,m2);++i)
	f[0][i][0]=INF,f[i][0][0]=INF;
	
	
	for(i=1;i<=m1;++i)
	for(j=1;j<=m2;++j)
	{
		for(k=0;k<=min(m1,m2);++k)
		{
			f[i][j][k]=min(f[i-1][j][k],f[i][j-1][k]);
		}
		if(a1[i]==a2[j]){
			int p=find(f[i-1][j-1],a1[i]);
			if(p!=0){
				f[i][j][p]=a1[i];
				maxx=max(maxx,p);
				ans[p]=(node){i,j};
			}
		}
	}
	cout<<maxx<<endl;
	for(i=1;i<=maxx;++i)
	cout<<a1[ans[i].x]<<' ';
	cout<<endl;
	
    return 0;
}

