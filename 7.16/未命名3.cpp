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

LL sum,a[maxn];


int main()
{
	int i,j,k,n;
	for(n=2;n<=20;++n){
		for(i=1;i<=n;++i)
	a[i]=i-1;
	sum=0;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	sum+=a[i]^a[j];
	
	cout<<n<<' '<<(double)sum/n/n<<endl;
	}
    return 0;
}

