#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm> 
#define LL long long
using namespace std;

const int maxn=1010;
const int INF=199999999;

int n,d,v,a[maxn];
LL f[maxn],sum=0;


LL work()
{
	int i,j,k;
	LL ans=0,sum=0;
	for(i=1;i<v;++i)
	{
		memset(f,0,sizeof(f));
		f[0]=1;
		for(j=i+1;j<=v;++j)
		{
			for(k=d-sum;k>=0;--k)
			{
				//cout<<k<<"###";
				if(k-a[j]>=0)f[k]+=f[k-a[j]];
				//if(i==3)cout<<k<<' '<<f[k]<<endl;
				
				//cout<<f[k]<<endl;
				if(j==v&&k>d-sum-a[i])ans+=f[k];				
			}
			
		}		
		sum+=a[i];
	//	cout<<ans<<endl;
	}
	if(sum<=d&&sum+a[v]>d)++ans;
	
	if(a[1]>d)ans=0;
	
	
	return ans;
}


int main()
{
	cin>>n;
	int i;
	for(i=1;i<=n;++i)
	{
		cin>>v>>d;
		for(int j=1;j<=v;++j)
		scanf("%d",&a[j]); 
		a[++v]=INF;
		sort(a+1,a+v+1);
		cout<<i<<' '<<work()<<'\n';		
	 } 
	
	
    return 0;
}

