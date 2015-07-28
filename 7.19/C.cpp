#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
ll f[130][130][130];
void Add(int x, int y, int z, ll d)
{
	for (int i = x; i <= N; i += (i & -i))
		for (int j = y; j <= N; j += (j & -j))
			for (int k = z; k <= N; k += (k & -k))
				f[i][j][k] += d;
}
ll Sub(int x, int y, int z)
{
	ll ans = 0;
	for (int i = x; i; i -= (i & -i))
		for (int j = y; j; j -= (j & -j))
			for (int k = z; k; k -= (k & -k))
				ans += f[i][j][k];
	return ans;
}
int main( )
{
	int type, x, y, z;
	ll d;
	int px, py, pz, qx, qy, qz;
	scanf("%d", &N);
	while (1)
	{
		scanf("%d", &type);
		if (type == 3) break;
		if (type == 1)
		{
			scanf("%d %d %d %lld", &x, &y, &z, &d);
			++ x, ++ y, ++ z;
			Add(x, y, z, d);
		}
		else
		{
			scanf("%d %d %d %d %d %d", &px, &py, &pz, &qx, &qy, &qz);
			++ px, ++ py, ++ pz, ++ qx, ++ qy, ++ qz;
			ll ans = Sub(qx, qy, qz);
			ans -= Sub(px - 1, qy, qz);
			ans -= Sub(qx, py - 1, qz);
			ans -= Sub(qx, qy, pz - 1);
			ans += Sub(px - 1, py - 1, qz);
			ans += Sub(px - 1, qy, pz - 1);
			ans += Sub(qx, py - 1, pz - 1);
			ans -= Sub(px - 1, py - 1, pz - 1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}

