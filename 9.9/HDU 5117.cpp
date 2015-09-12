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

LL dp[51][8];
int s[51][51];



int main()
{
	int T;
	scanf("%d",&T);
	for (int cas = 1; cas <= T; ++cas){
		int n,m,k;
		scanf("%d%d",&n,&m);
		memset(s,0,sizeof(s));
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d",&k);
			int x;
			for (int j = 1; j <= k; ++j)
			{
				scanf("%d",&x);
				s[i][x] = 1;
			}
		}
		LL ans = 0;
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
				{
					for (int p = 1; p <= m; ++p)
					{
						for (int st = 0; st < 8; ++st)
						{
							int pst = st;
							dp[p][st] = dp[p-1][st];
							if (s[p][i])pst ^= (1 << 2);
							if (s[p][j])pst ^= (1 << 1);
							if (s[p][k])pst ^= 1;
							dp[p][st] = (dp[p][st] + dp[p-1][pst]) % MOD;							
						}						
					}					
					ans = (ans + dp[m][7]) % MOD;
				}
		printf("Case #%d: %d\n",cas, (int)ans);
	}
	
	
	
	return 0;
}


