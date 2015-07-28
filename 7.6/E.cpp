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
const int INF=199999999;

LL n;
LL a[maxn];
LL sub,sum;

LL find(LL n)
{
	if(n<0)n=-n;
	LL ans=1;
	while(ans<=n)ans*=10;
	ans/=10;
	return ans;	
}

LL work()
{
	sub=sum-a[n];
	
	if(sub==0)
	{
		cout<<"Input has no error.\n";
		return -1;
	}
	if(sub%9!=0){
		cout<<"Unrecoverable error.\n";
		return -1;
	}
	sub/=9;
	LL k;
	k=find(sub);
	if(sub%k!=0)
	{
		cout<<"Unrecoverable error.\n";
		return -1;
	}
//	cout<<"k="<<k<<endl;
	sub/=k;
//	cout<<sub<<endl;
	LL i,x,y;
	for(i=0;i<n;++i)
	{
		x=a[i]/k/10%10;
		y=a[i]/k%10;
		if(x==0&&a[i]/k/100==0)continue; 
		if(y==0&&a[i]/k/100==0)continue;
	//	cout<<x<<' '<<y<<endl;
		if(x-y==sub)
		{
			a[i]-=sub*9*k;
			//cout<<"###"<<i<<endl;
			return i;
		}
		
	}
	
	cout<<"Unrecoverable error.\n";
	return -1;
	
	
}

int main()
{
	scanf("%lld",&n);
	int i;
	for(i=0;i<n;++i)
	{scanf("%lld",&a[i]);sum+=a[i];}
	scanf("%lld",&a[i]);
	LL k=0;
	k=work();
	if(k!=-1)
	{
		cout<<"Error in record #"<<k+1<<". Correct number is: "<<a[k]<<".\n";
	}
	
	
	
	
    return 0;
}

