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

int m,n,a[maxn],b[maxn]; 
int col[maxn];

bool okin(int i)
{
	int j;
	for(j=1;j<i;++j)
	{
		if((a[j]<a[i]&&a[i]<b[j]&&b[j]<b[i])||(a[i]<a[j]&&a[j]<b[i]&&b[i]<b[j])) 
		{
			if(col[j]==1)return 0;		
		}
	} 
	return 1;
}

bool okout(int i)
{
	int j;
	for(j=1;j<i;++j)
	{
		if((a[j]<a[i]&&a[i]<b[j]&&b[j]<b[i])||(a[i]<a[j]&&a[j]<b[i]&&b[i]<b[j])) 
		{
			if(col[j]==0)return 0;		
		}
	} 
	return 1;
}


int main()
{
	cin>>n>>m;
	int i;
	for(i=1;i<=m;++i) 
	{
		cin>>a[i]>>b[i];
		if(a[i]>b[i])swap(a[i],b[i]);
		//cout<<a[i]<<b[i]<<endl;
		if(okin(i))col[i]=1;
		else if(okout(i))col[i]=0;
		else {
			cout<<"the evil panda is lying again\n";
			return 0;
		}			
	} 
		
	cout<<"panda is telling the truth...\n";
		
	
	
    return 0;
}

