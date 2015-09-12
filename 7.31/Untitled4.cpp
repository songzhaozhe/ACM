#include<set>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20005;

struct Circle {
	int x, y, r;

	void in() {
		scanf("%d%d%d", &x, &y, &r);
	}

	bool contain(const Circle &c) {
		return r > c.r && (r - c.r) * (r - c.r) > (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y);
	}

	double up(int p) {
		return y + sqrt(r * r - (x - p) * (x - p));
	}

	double down(int p) {
		return y - sqrt(r * r - (x - p) * (x - p));
	}
};

bool operator < (const Circle &a, const Circle &b) {
	return a.r > b.r;
}

Circle c[N];

struct cirCmp {
	int id;

	cirCmp(int id = 0) : id(id) {}

	int rid() const {
		return id >= 0 ? id : -id;
	}

	double getp(int cur) const{
		return id >= 0 ? c[id].down(cur) : c[-id].up(cur);
	}
};

int cur;

int n;

bool operator < (const cirCmp &a, const cirCmp &b) {
	if (a.rid() == b.rid()) {
		return a.id < b.id;
	} else {
		return a.getp(cur) > b.getp(cur);
	}
}

int fa[N];

vector<int> ch[N];

int sg(int u) {
	int ret = 0;
	for (int i = 0; i < (int)ch[u].size(); ++i) {
		ret ^= sg(ch[u][i]);
	}
	return ret + 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<pair<int, int> > evt;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			c[i].in();
			ch[i].clear();
			fa[i] = -1;
		}
		sort(c+1, c + n + 1);
		for (int i = 1; i <= n; ++i) {
			evt.push_back(make_pair(c[i].x - c[i].r, i));
			evt.push_back(make_pair(c[i].x + c[i].r, -i));
		}
		sort(evt.begin(), evt.end());
		set<cirCmp> tr;
		for (int i = 0; i < (int)evt.size(); ++i) {
			cur = evt[i].first;
			if (evt[i].second >= 0) {
				int id = evt[i].second;	
				set<cirCmp>::iterator it = tr.upper_bound(cirCmp(id));
				if (it != tr.end()) {
					int pid = (*it).rid();
					if (c[pid].contain(c[id])) {
						fa[id] = pid;
						ch[pid].push_back(id);
					} else {
						if (fa[pid] != -1) {
							fa[id] = fa[pid];
							ch[fa[pid]].push_back(id);
						}
					}
				}
				tr.insert(cirCmp(-id));
				tr.insert(cirCmp(id));
			} else {
				int id = -evt[i].second - 1;
				tr.erase(cirCmp(id));
				tr.erase(cirCmp(-id));
			}
		}
		/*
		for (int i = 0; i < n; ++i) {
			printf("%d : ", i);
			for (int j = 0; j < (int)ch[i].size(); ++j) {
				printf("%d ", ch[i][j]);
			}
			printf("\n");
		}
		*/
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (fa[i] == -1) {
				ans ^= sg(i);
			}
		}
		puts(ans ? "Alice" : "Bob");
	}
	return 0;
}

