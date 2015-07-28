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

const int maxn=1000010;
const int INF=199999999;

int a[maxn];
int ok[maxn];
int n;

int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;++i)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ok[0]=1;
	for(i=1;i<=1e6;++i)
	{
		for(j=1;j<=n;++j)
		if(i-a[j]>=0&&ok[i-a[j]]){
			ok[i]=1;
			break;
		}
		if(!ok[i])break;
	}
	if(i!=1e6+1)
	cout<<i<<endl;
	else cout<<-1<<endl;
	
	
	
    return 0;
}

