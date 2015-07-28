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

const int maxn=200010;
const int INF=1e9+10;

int n,a[maxn],k;

bool ok(LL t)
{
	int i,tmp;
	LL cnt=0;
	for(i=1;i<=n;++i)
	{
		tmp=a[i]-t;
		if(tmp>0){
			if(k==1)return 0;
			cnt+=(tmp+k-2)/(k-1);
		}
	}
	if(cnt>t)return 0;
	else return 1;
}

int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;++i)
	scanf("%d",&a[i]);
	scanf("%d",&k); 
	int l=0,r=INF;
	while(l<r-1)
	{
		int mid=(r-l)/2+l;
		//cout<<l<<' '<<r<<endl;
		if(ok((LL)mid))r=mid;
		else l=mid;
	}
	cout<<r<<'\n';
	
    return 0;
}

