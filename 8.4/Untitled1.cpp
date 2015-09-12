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

int main()
{
	multiset<int>s;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int x,y;
		scanf("%d",&x);
		if(x==1){
			scanf("%d",&y);
			s.insert(y);
		}
		if(x==2){
			if(s.size()!=0)
			s.erase(s.begin());
		}
	 	if(x==3){
	 		int ans=0;
	 		if(s.size()!=0)
	 		ans = *(--s.end());
	 		printf("%d\n",ans);
		 }
	}
	return 0;
}


