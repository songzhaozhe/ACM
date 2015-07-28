#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <assert.h>

using namespace std;

typedef long long int64;

#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

#define x first
#define y second

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;

template<class T> T abs(T x){return x < 0 ? -x : x;}

struct point
{
	point(){};
	int x, y;
};

const int N = 50005;

long long f[N];
point a[N];

long long cal(point a, point b)
{
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

int main()
{
	int n, q;
	bool first = true;
	while (scanf("%d%d", &n, &q) == 2)
	{
		if (n == 0 && q == 0) break;
		if (first) first = false;
		else puts("");
		for (int i = 1; i <= n; ++i)
			scanf("%d%d", &a[i].x, &a[i].y);
		a[n + 1] = a[1];
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += cal(a[i], a[i + 1]);
		ans = abs(ans);
		f[0] = 0;
		for (int i = 1; i <= n; ++i)
			f[i] = f[i - 1] + cal(a[i], a[i + 1]);
		while (q--)
		{
			int p, q;
			scanf("%d%d", &p, &q);
			if (p > q) swap(p, q);
			long long gxx = abs(f[q] - f[p] + cal(a[q + 1], a[p + 1]));
			long long ysy = ans - gxx;
			long long tmp = min(gxx, ysy);
			printf("%lld.", tmp / 2);
			if (tmp % 2 == 0) printf("0\n");
			else printf("5\n");
		}
	}
	return 0;
}
