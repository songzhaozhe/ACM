#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<ctime>
using namespace std;

const int maxn=20010;
const int INF=199999999;


int main()
{
	freopen("a.out","w",stdout);
	srand(time(NULL));
	int n=20,i;
	cout<<n+1<<endl;
	long long ans=0;
	for(i=1;i<=10;++i)
	{
		int t=int(rand()*maxn);
		ans+=t;
		cout<<t<<endl;
	}
	cout<<104204234<<endl;
	ans+=14204234;
	for(;i<=20;++i)
	{
		int t=int(rand()*maxn);
		ans+=t;
		cout<<t<<endl;
	}
	cout<<ans<<endl;
	
    return 0;
}

