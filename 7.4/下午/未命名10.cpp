#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#define LL long long
using namespace std;

const int maxn=1000010;
const int MOD=20100713;
LL T,n,k;
//k! * [(k + 1)^(n - k) - k^(n - k)];

long long exp(LL k,LL n)
{
	LL ans=1;
	while(n>0)
	{
		if(n&1)
		ans*=k;
		ans%=MOD;
		k*=k;
		k%=MOD;
		n>>=1;
	}
	return ans;
}


LL fac[maxn];

LL work(LL n,LL k)
{
	return fac[k]*((exp(k+1,n-k)+MOD-exp(k,n-k))%MOD)%MOD;
}


int main()
{
	LL i,ans;
	fac[0]=1;
	for(i=1;i<maxn;++i)
	fac[i]=fac[i-1]*i,fac[i]%=MOD;
	//cout<<fac[4]<<endl;
	cin>>T;	
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		ans=work(n,k);
		printf("%lld\n",ans);		
	}
	
    return 0;
}

