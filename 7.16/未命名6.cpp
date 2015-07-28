#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>
#include <climits>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

#define foreach(it,e) for (__typeof(e.begin()) it = e.begin(); it != e.end(); it++)

#define sqr(x) ((x) * (x))
#define abs(x) (((x) > 0) ? (x) : (-(x))) 
#define lowbit(x) ((x) & (-(x)))

using namespace std;

const int N = 555;

int n, m;
int a[N], b[N];
int best[N][N];
pair<int, int> prev[N][N];

void solve() {
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", b + i);
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			best[i][j] = 0;
			prev[i][j] = make_pair(0, 0);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				best[i][j] = 1;
				for (int k = i - 1; k >= 1; --k) {
					if (a[k] < a[i] && best[i][j] < best[k][j - 1] + 1) {
						best[i][j] = best[k][j - 1] + 1;
						prev[i][j] = make_pair(k, j - 1);
					}
				}
			} else {
				best[i][j] = best[i][j - 1];
				prev[i][j] = make_pair(i, j - 1);
			}
		}
	}
	
	pair<int, int> ans = make_pair(1, 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (best[ans.first][ans.second] < best[i][j]) {
				ans = make_pair(i, j);
			}
		}
	}
	
	printf("%d\n", best[ans.first][ans.second]);
	vector<int> trace;
	for (; ans.first && ans.second; ) {
		if (a[ans.first] == b[ans.second]) {
			trace.push_back(a[ans.first]);
		}
		ans = prev[ans.first][ans.second];
	}
	reverse(trace.begin(), trace.end());
	for (int i = 0; i < (int)trace.size(); ++i) {
		printf("%d%s", trace[i], (i == (int)trace.size() - 1) ? "\n" : " ");
	}
}

int main() {
	for (; ~scanf("%d", &n); solve());
	return 0;
}
