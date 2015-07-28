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

int n;
int a[40]; 

int main()
{
	cin>>n;
	int i,x;
	for(i=1;i<=n;++i) 
	{
		cin>>x;
		a[x]++;	
	}
	int ans=0;
	for(i=0;i<=30;++i)
	while(a[i]&&a[i+1]){
		--a[i];
		--a[i+1];
		++ans;
	} 
	cout<<n-ans<<endl;
	
    return 0;
}

