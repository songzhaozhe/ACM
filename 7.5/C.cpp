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
int main()
{
	cin>>p;
	while(p--)
	{
		ans=0;
		scanf("%d%d",&k,&n);
		if(n%3==0)++ans;
		bigl=n/3+1;
		bigr=n/2;
		if(n%2==0)--bigr;
		
		ans+=3*(bigl+bigr)*(bigr-bigl+1)/2-n*(bigr-bigl+1);
		
	//	int x=n-bigl,y=n-bigr;
		/*
		if((y-x+1)%2==0)ans+=(y-x+1)/2;
		else{
			if(x%2==0)
			ans+=(y-x+2)/2;
			else ans+=(y-x)/2;
		}
		*/
		//ans-=bigr-bigl+1;
		printf("%d %d\n",k,ans); 
	//	cout<<ans<<endl;
		
		
	}
	
    return 0;
}

