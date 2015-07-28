#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=20010;
const int INF=199999999;

int a[4],b[4];

bool solve()
{
	int t1,t2;
	if(a[1]>=a[2]&&b[1]>=b[2]){
		t1=a[1];
		t2=b[1]-b[2];	
		if(t1>=a[3]&&t2>=b[3])return 1;
		if(t1>=b[3]&&t2>=a[3])return 1;

		t1=b[1];
		t2=a[1]-a[2];
		if(t1>=a[3]&&t2>=b[3])return 1;
		if(t1>=b[3]&&t2>=a[3])return 1;
	}
	if(a[1]>=b[2]&&b[1]>=a[2])
	{
		t1=b[1];
		t2=a[1]-b[2];	
		if(t1>=a[3]&&t2>=b[3])return 1;
		if(t1>=b[3]&&t2>=a[3])return 1;	
		t1=a[1];
		t2=b[1]-a[2];	
		if(t1>=a[3]&&t2>=b[3])return 1;
		if(t1>=b[3]&&t2>=a[3])return 1;	
	}
		
	return 0;
}
	

int main()
{
	for(int i=1;i<=3;++i)
	scanf("%d%d",&a[i],&b[i]);
	
	if(solve())printf("YES\n");
	else printf("NO\n");
	
    return 0;
}

