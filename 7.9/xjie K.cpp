#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[1005], s2[1005];
bool ava[1005], fb[1005];
int dp[1005];
int main()
{
	int i, j, k, l, n, m;
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	n = strlen(s1 + 1);
	m = strlen(s2 + 1);
	memset(ava, 0, sizeof(ava));
	memset(fb, 0, sizeof(fb));
	for (i = 1; i <= m; ++ i)
	{
		fb[i] = 1;
		for (j = 1; j <= i; ++ j)
		{
			if (s2[j] != s2[m - i + j])
			{
				fb[i] = 0;
				break;
			}
		}
	}
	for (i = 1; i + m - 1 <= n; ++ i)
	{
		ava[i] = 1;
		for (j = 1; j <= m; ++ j)
		{
			if (s1[i + j - 1] != '?' && s1[i + j - 1] != s2[j])
			{
				ava[i] = 0;
				break;
			}
		}
	}
	memset(dp, 0, sizeof(dp));
	for (i = n; i >= 1; -- i) if (ava[i])
	{
		dp[i] = 1;
		for (j = i + 1; j <= n; ++ j) if (ava[j])
		{
			if ((i + m > j && fb[i + m - j]) || i + m <= j)
			{
				dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
	}
	int ans = 0;
	for (i = 1; i <= n; ++ i)
	{
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}

