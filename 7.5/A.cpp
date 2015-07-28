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

const int maxn=100000001;
const int INF=199999999;

LL T,n;

LL f[maxn]={0};
LL dfs(LL i)
{
    if(i>maxn)	cout<<i<<endl;
	if(f[i])return f[i];
	if(i%2==0){
		f[i]=max(i,dfs(i/2));
	}
	else f[i]=max(i,dfs(i*3+1));
	return f[i];	
}


int main()
{
	
	int i;
	//f[0]=0;
	f[1]=1;
	f[2]=2;
	f[4]=4;
	cout<<dfs(9999)<<"####"<<endl;
	
	for(i=1;i<=100000;++i)
	{
		dfs(i);	
	 } 
	
	LL x;
	cin>>T;
	while(T--)
	{
		cin>>x>>n;
		cout<<f[n]<<endl; 
		
	 } 
	
	
    return 0;
}

