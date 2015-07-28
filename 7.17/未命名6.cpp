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

const int maxn=60;
const int INF=199999999;

int a[maxn][maxn];
int f[maxn][maxn][maxn];
int n,k;


int main()
{
	cin>>n>>k;
	int i,j,o,oo;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	scanf("%d",&a[i][j]);
	
	for(o=1;o<=k;++o)
	f[1][1][o]=a[1][1];
	
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	for(o=1;o<=k;++o)
	{
		//f[i][j][o]+=a[i][j];
		for(oo=0;oo<=o;++oo)
		f[i][j][o]=max(f[i-1][j][oo]+f[i][j-1][o-oo],f[i-1][j][o-oo]+f[i][j-1][o]);
		f[i][j][o]+=a[i][j];
	}
	cout<<f[n][n][k]<<endl;
		
	
	
    return 0;
}

