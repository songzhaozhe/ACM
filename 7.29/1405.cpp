#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=1000005;

bool isp(int n)
{
	int i;
	if(n==2)return 1;
	for(i=2;i<=sqrt(n)+1;++i)
	if(n%i==0)return 0;
	return 1;
}

int main()
{
	freopen("a.out","w",stdout);
	int maxn=3333;
	int cnt=0;
	for(int i=2;i<=maxn;++i)
	if(isp(i)){
		printf("%d,",i);
		++cnt;
	}
	cout<<endl;
	cout<<cnt<<endl;
	
	return 0;
}


