#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define Mod1 1000000009LL
#define Mod2 111111113LL
using namespace std;
typedef long long ll;
struct node
{
	ll x, y;
	node() {}
	node(ll x, ll y) : x(x), y(y) {}
};
bool operator < (const node& p1, const node& p2) { return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y); }
map<node, int> mp;
node hash1[200010], hash2[200010], hash3[200010];
char str1[200005], str2[200005];
int ans1 = -1, ans2 = -1;
int n, m;
ll Mul1[200010], Mul2[200010];
node operator - (const node& p1, const node& p2) { return node((p1.x - p2.x + Mod1) % Mod1, (p1.y - p2.y + Mod2) % Mod2); }
node operator * (const node& p1, int d) { return node(p1.x * Mul1[d] % Mod1, p1.y * Mul2[d] % Mod2); }
node gethash1(int x, int y)
{
	return (hash1[y] - hash1[x - 1] * (y - x + 1));
}
node gethash2(int x, int y)
{
	return (hash2[y] - hash2[x - 1] * (y - x + 1));
}
node gethash3(int x, int y)
{
	return (hash3[x] - hash3[y + 1] * (y - x + 1));
}
int main( )
{
	scanf("%s", str1 + 1);
	scanf("%s", str2 + 1);
	n = (int )strlen(str1 + 1), m = (int )strlen(str2 + 1);
	for (int i = 1; i <= n; i ++) str1[i + n] = str1[i];
	for (int i = 1; i <= m; i ++) str2[i + m] = str2[i];
	Mul1[0] = Mul2[0] = 1LL;
	for (int i = 1; i <= 2 * n; i ++) Mul1[i] = Mul1[i - 1] * 31 % Mod1;
	for (int i = 1; i <= 2 * n; i ++) Mul2[i] = Mul2[i - 1] * 29 % Mod2;
	for (int i = 1; i <= 2 * n; i ++)
	{
		hash1[i].x = (hash1[i - 1].x * 31 + str1[i] - 'a') % Mod1;
		hash1[i].y = (hash1[i - 1].y * 29 + str1[i] - 'a') % Mod2;
	}
	for (int i = 1; i <= 2 * m; i ++)
	{
		hash2[i].x = (hash2[i - 1].x * 31 + str2[i] - 'a') % Mod1;
		hash2[i].y = (hash2[i - 1].y * 29 + str2[i] - 'a') % Mod2;
	}
	for (int i = 2 * n; i >= 1; i --)
	{
		hash3[i].x = (hash3[i + 1].x * 31 + str1[i] - 'a') % Mod1;
		hash3[i].y = (hash3[i + 1].y * 29 + str1[i] - 'a') % Mod2;
	}
	for (int i = 1; i <= m; i ++)
		mp[gethash2(i, i + m - 1)] = i;
	for (int i = 1; i <= n; i ++)
	{
		int mid = (n + m + 1) >> 1;
		node tmpx = gethash3(i, i + mid - 1);
		node tmpy = gethash1(i + mid, i + n - 1);
		if ((n + m) & 1) tmpy = gethash1(i + mid - 1, i + n - 1);
		node get = tmpx - tmpy * m;
		if (mp.count(get))
		{
			ans1 = i, ans2 = mp[get];
			break;
		}
	}
	if (ans1 == -1) printf("No\n");
	else printf("Yes\n%d %d\n", ans1, ans2);
	return 0;
}
