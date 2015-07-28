#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int tot = 1;
int e[200001], next[200001], cost[200001], g[100001];
int depth[100001], d[100001][20];
int q[200001];
bool vis[200001];
int n, m;
int D[200001];
void Add(int u, int v, int w)
{
	e[tot] = v; next[tot] = g[u]; cost[tot] = w; g[u] = tot ++;
	e[tot] = u; next[tot] = g[v]; cost[tot] = w; g[v] = tot ++;
}
int LCA(int x, int y)
{
	if (x == y) return x;
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = 18; i >= 0; i --)
		if (depth[d[x][i]] >= depth[y]) x = d[x][i];
	if (x == y) return x;
	for (int i = 18; i >= 0; i --)
		if (d[x][i] != d[y][i]) x = d[x][i], y = d[y][i];
	return d[x][0];
}
int main( )
{
int T;
scanf("%d",&T);
while(T--)
{
	int x, y, z;
	scanf("%d%d", &n,&m);
	for (int i = 1; i < n; i ++)
	{
		scanf("%d %d %d", &x, &y, &z);
		//++ x, ++ y;
		Add(x, y, z);
	}
	int h = 0, t = 1;
	q[t] = 1; vis[1] = true;
	depth[1] = 1;
	while (h < t)
	{
		int k = q[++ h];
		for (int i = g[k]; i; i = next[i])
			if (!vis[e[i]])
			{
				vis[e[i]] = true;
				depth[e[i]] = depth[k] + 1;
				D[e[i]] = D[k] + cost[i];
				d[e[i]][0] = k;
				for (int j = 1; j <= 18; j ++)
					d[e[i]][j] = d[d[e[i]][j - 1]][j - 1];
				q[++ t] = e[i];
			}
	}
	//scanf("%d", &m);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d %d", &x, &y);
	//	++ x, ++ y;
		int tmp = LCA(x, y);
		printf("%d\n", D[x] + D[y] - 2 * D[tmp]);
	}
}
	return 0;
}

