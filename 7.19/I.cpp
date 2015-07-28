#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;

const int maxn=50;


const int MOD = 10000;


struct hint{
	int v[500];
	int len;
	
	hint(){
		memset(v,0,sizeof(v));
		len=0;
	}
	
	hint operator +(const hint &b)
	{
		hint ans;
		ans.len=max(len,b.len);
		int i;
		for(i=0;i<ans.len;++i)
		{
			ans.v[i]+=v[i]+b.v[i];
			ans.v[i+1]=ans.v[i]/MOD;
			ans.v[i]%=MOD;
		}
		while(ans.v[ans.len]!=0)
		{
			ans.v[ans.len+1]+=ans.v[ans.len]/MOD;
			ans.v[ans.len]%=MOD;
			ans.len++;
		}
		return ans;
	}
	hint operator *(const hint &b)
	{
		hint ans;
		if(len==0||b.len==0)
		return ans;	
		
		ans.len=len+b.len-1;
		int i,j;
		for(i=0;i<len;++i)
		for(j=0;j<b.len;++j)
		{
			ans.v[i+j]+=v[i]*b.v[j];
			if(ans.v[i+j]>MOD)
			{
				ans.v[i+j+1]+=ans.v[i+j]/MOD;
				ans.v[i+j]%=MOD;
			}
		}
			
		
		for(i=0;i<ans.len;++i)
		{
			ans.v[i+1]+=ans.v[i]/MOD;
			ans.v[i]%=MOD;
		}
		while(ans.v[ans.len]!=0)
		{
			ans.v[ans.len+1]+=ans.v[ans.len]/MOD;
			ans.v[ans.len]%=MOD;
			ans.len++;
		}	
		return ans;
	}	
	
	void print()
	{
		if(len==0){printf("0\n");return;}
		int i;
		printf("%d",v[len-1]);
		for(i=len-2;i>=0;--i)
		printf("%04d",v[i]);
		printf("\n");
	}
	
};
	
hint c[maxn][maxn];
int n,m,KK;
hint f[maxn][maxn],d[maxn][maxn],s[maxn][maxn];
hint g[maxn];
hint one;

void init()
{
	//hint one;
	one.len=1;
	one.v[0]=1;
	int i,j;
	for(i=0;i<maxn;++i)
	{
		c[i][0]=one;
		c[i][i]=one;
	}
	for(i=2;i<maxn;++i)
	for(j=1;j<i;++j)
	c[i][j]=c[i-1][j]+c[i-1][j-1];
	int k,x;
	for(j=0;j<=m;++j)
	for(k=0;k<=m;++k)
	for(x=max(k-j,0);x<=min(min(k,KK),m-j);++x)
	s[j][k]=s[j][k]+c[k][x]*c[m-k][m-j-x];
	
}
	
	

int main()
{
	cin>>m>>n>>KK;
	int i,j,k;
	init();
//c[2][1].print();	
	
	//hint tmp;
	for(i=0;i<=m;++i)
	f[1][i]=c[m][i];
	
	for(i=2;i<=n;++i)
	for(j=0;j<=m;++j)
	for(k=0;k<=m;++k)	
	{
		f[i][j]=f[i][j]+f[i-1][k]*s[j][k];
	}
	//for(i=0;i<=2;++i)
	//f[1][i].print();
	
	hint ans;
	for(j=0;j<=m;++j)
	ans=ans+f[n][j];
	ans.print();
	
	
	
}

