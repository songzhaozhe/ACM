#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=1000005;

int a[4];

void dfs ( int p ){
	if (p == 4){
		int tmp = 0; 
		for (int i = 0; i < 4; ++i)
		tmp ^= a[i];
		if (tmp == 0){
			for (int i = 0; i < 4; ++i)
			printf("%d ", a[i]);
			puts("");
		}
		return;
	}
	a[p] = 0;
	dfs(p+1);
	a[p] = 1; 
	dfs(p+1);
	return;
}


int main()
{
	dfs(0);
	
	
	return 0;
}


