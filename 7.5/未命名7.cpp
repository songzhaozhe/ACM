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

int p,k,n,ans,bigl,bigr,midl,midr;

void check(int i,int j,int k)
{
	if(i>j||j>k)return; 
	if(i==j||j==k||i==k)
	++ans;
	else ans+=2;
	
} 

void work(int k)
{
	int rem=n-k;
	int i,j;
	for(i=1;i<=rem/2;++i)
	check(i,n-i-k,k);
}


int main()
{
	int i;
	freopen("a.out","w",stdout);
	for(n=1;n<=10000;++n){ 
		if(n<=5000) {cout<<0<<',';continue;}
		ans=0;
		if(n%3==0)++ans;
		bigl=n/3+1;
		bigr=n/2;
		if(n%2==0)--bigr;
		//ans=0;
		for(i=bigl;i<=bigr;++i)
		work(i);
		cout<<ans<<',';
		
	}
	
	
    return 0;
}

