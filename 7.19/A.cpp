#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
int M[100001];
int a, b, k, dfs_clock = 2;
int stack[1000001];
int vis[1000001];
char str[1000001];
char Print(int x)
{
	if (x >= 0 && x <= 9) return x + '0';
	else return x - 10 + 'A';
}
void Work()
{
	++ dfs_clock;
	int top = 0, len = 0;
	int tmp = a / b;
	while (tmp) stack[++ top] = tmp % k, tmp /= k;
	for (int i = top; i >= 1; i --)
		str[len ++] = Print(stack[i]);
	if (top == 0) str[len ++] = Print(0);
	if (a % b)
	{
		str[len ++] = '.';
		tmp = a % b;
		int idx = -1, idy = -1;
		bool ok = false;
		top = 0;
		for (int pos = 0; ; pos ++)
		{
			if (vis[tmp] == dfs_clock)
			{
				idx = M[tmp] + 1, idy = pos;
				break;
			}
			vis[tmp] = dfs_clock;
			M[tmp] = pos;
			stack[++ top] = tmp * k / b;
			tmp = tmp * k % b;
			if (tmp == 0) { ok = true; break; }
		}
		if (ok)
		{
			for (int i = 1; i <= top; i ++) str[len ++] = Print(stack[i]);
		}
		else
		{
			for (int i = 1; i < idx; i ++) str[len ++] = Print(stack[i]);
			str[len ++] = '(';
			for (int i = idx; i <= idy; i ++)
				str[len ++] = Print(stack[i]);
			str[len ++] = ')';
		}
	}
	str[len] = '\0';
	puts(str);
}
int main( )
{
	while (1)
	{
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		scanf("%d", &k);
		Work();
	}
	return 0;
}

