#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 22222;
const int M = 1111 * 1111 * 2;

struct EdgeList {
	int size;
	int last[N];
	int succ[M], other[M], flow[M];
	void clear(int n) {
		size = 0;
		fill(last, last + n, -1);
	}
	void add(int x, int y, int c) {
		succ[size] = last[x];
		last[x] = size;
		other[size] = y;
		flow[size++] = c;
	}
} e;

char a[N], b[N];

int n, source, target;
int dist[N], curr[N], visit[N];

inline void add(int x, int y, int c) {
	e.add(x, y, c);
	e.add(y, x, 0);
}

inline bool bfs() {
	vector<int> queue;
	for (int i = 0; i < n; ++i) {
		curr[i] = e.last[i];
		dist[i] = -1;
	}
	queue.push_back(target);
	dist[target] = 0;
	for (int head = 0; head < (int)queue.size(); ++head) {
		int x = queue[head];
		for (int i = e.last[x]; ~i; i = e.succ[i]) {
			int y = e.other[i];
			if (e.flow[i ^ 1] && dist[y] == -1) {
				dist[y] = dist[x] + 1;
				queue.push_back(y);
			}
		}
	}
	return ~dist[source];
}

inline int dfs(int x, int ans) {
	if (x == target) {
		return ans;
	}
	int delta = ans;
	for (int &i = curr[x]; ~i; i = e.succ[i]) {
		int y = e.other[i];
		if (e.flow[i] && dist[x] == dist[y] + 1) {
			int num = dfs(y, min(e.flow[i], delta));
			e.flow[i] -= num;
			e.flow[i ^ 1] += num;
			if ((delta -= num) == 0) {
				break;
			}
		}
	}
	return ans - delta;
}

inline int solve() {
	int ans = 0;
	for (; bfs(); ans += dfs(source, INT_MAX));
	return ans;
}

int main() {
	scanf("%s%s", a + 1, b + 1);

	int lena = (int)strlen(a + 1);
	int lenb = (int)strlen(b + 1);

	n = lena + lenb + 2;
	source = 0;
	target = lena + lenb + 1;
	e.clear(n);
	
	for (int i = 1; i <= lena; ++i) {
		if (a[i] == '0') {
			add(source, i, INT_MAX);
		} else if (a[i] == '1') {
			add(i, target, INT_MAX);
		}
	}
	for (int i = 1; i <= lenb; ++i) {
		if (b[i] == '0') {
			add(source, i + lena, INT_MAX);
		} else if (b[i] == '1') {
			add(i + lena, target, INT_MAX);
		}
	}
	
	for (int i = 1; i <= lena - lenb + 1; ++i) {
		for (int j = 1; j <= lenb; ++j) {
			e.add(i + j - 1, j + lena, 1);
			e.add(j + lena, i + j - 1, 1);
		}
	}

	printf("%d\n", solve());
	
	vector<int> queue;
	queue.push_back(source);
	visit[source] = true;
	for (int head = 0; head < (int)queue.size(); ++head) {
		int x = queue[head];
		for (int i = e.last[x]; ~i; i = e.succ[i]) {
			int y = e.other[i];
			if (!visit[y] && e.flow[i]) {
				visit[y] = true;
				queue.push_back(y);
			}
		}
	}
	
	for (int i = 1; i <= lena; ++i) {
		if (a[i] == '?') {
			a[i] = (visit[i] ? '0' : '1');
		}
	}
	for (int i = 1; i <= lenb; ++i) {
		if (b[i] == '?') {
			b[i] = (visit[i + lena] ? '0' : '1');
		}
	}
	
	puts(a + 1);
	puts(b + 1);
	
	return 0;
}

