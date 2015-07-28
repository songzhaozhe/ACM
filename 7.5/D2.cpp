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

const int maxn=20010;
const int INF=199999999;

double f[101][210][101];
int T,n,x;
double l,r,stay,ans;

int main()
{
	cin>>T;
	int base,rear,i,j;
	
	while(T--)
	{
		scanf("%d%d%lf%lf",&x,&n,&l,&r);
		stay=1-l-r;
		memset(f,0,sizeof(f));
		rear=2*n+1;
		base=n+1;
		f[0][base][0]=1;
		int k;
		
		
		rear=base+k;
		for(i=1;i<=n;++i)
		{
			for(k=0;k<=n;++k)
			{
			rear=base+k;
			for(j=1;j<rear;++j)
			f[i][j][k]=f[i-1][j][k]*stay+f[i-1][j-1][k]*r+f[i-1][j+1][k]*l;
			
			f[i][j][k]=f[i-1][j-1][k-1]*r+f[i-1][j][k]*stay+f[i-1][j-1][k]*r;		
			}
		}
		ans=0;
		
		//cout<<f[4][15][4]<<"###"<<endl;
		for(k=0;k<=n;++k)
			{
			rear=base+k;
			for(j=1;j<=rear;++j)
			ans+=f[n][j][k]*1.0*k;
			}
		
		
		
		printf("%d %.4lf\n",x,ans);
	} 
	
    return 0;
}

