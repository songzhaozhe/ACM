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
const LL MOD=1000000007;
LL n,x,sum=0;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{scanf("%d",&x);
		sum+=((i)*(n-i+1))%MOD*x%MOD;
		sum%=MOD;
		
		//sum+=x*(((n+1)*i%MOD+MOD-n-i*i+1)%MOD+MOD)%MOD;
		}
		cout<<sum<<'\n'; 
		
	 } 
	
	
    return 0;
}

