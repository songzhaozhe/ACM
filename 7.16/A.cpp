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

double work(int n)
{
	double ans=0;
	int t=1,cnt=1,tmp2=0;
	while(t<n)
	{
		LL num1=0,num2=0,tmp;
		LL mul1,mul2;		
		if(n&t)
		{	
		tmp=n>>cnt<<cnt;
		tmp+=((n&tmp2)<<1);		
		tmp+=1;
		mul1=tmp/2;
		
		tmp=n>>cnt<<cnt;
		tmp+=(tmp2<<1);		
		tmp+=1;
		mul2=(tmp+1)/2;					
		}
		else{
			tmp=((n>>cnt)-1)<<cnt;			
			tmp+=(tmp2<<1);		
			tmp+=1;
			mul1=(tmp+1)/2;
			
			tmp=n>>cnt<<cnt;
			tmp+=((n&tmp2)<<1);		
			tmp+=((t&n)?1:0);
			mul2=(tmp+1)/2;
		}
		
		

		//cout<<tmp<<endl;
		ans+=((double)2.0)*t*mul1*mul2/n/n;
		//cout<<mul1<<' '<<mul2<<' '<<ans<<endl;
		t<<=1;
		cnt+=1;
		tmp2<<=1;
		tmp2+=1;
	}
	return ans;
}


int main()
{
	int k,n;
	cin>>k;
	int i;
	for(i=1;i<=k;++i)
	{
		scanf("%d",&n);
		printf("%.6f\n",work(n));
	}
		
	
	
    return 0;
}

