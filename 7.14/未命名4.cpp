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

int b[maxn];



int main()
{
	int n,m;
	cin>>m;
	int i,j;
	int ans=0;
	for(i=1;i<=m;++i)
	scanf("%d",&b[i]),ans^=b[i];
	cout<<ans<<endl;
	
	for(i=2;i<=m;++i)
	cout<<(b[i-1]^b[i])<<endl;
	
    return 0;
}

