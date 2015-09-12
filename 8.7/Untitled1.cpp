#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const int Mn = 1000 + 10;
const double Pi = acos(-1.0);
inline int dcmp(double x) {
	return x < -eps ? -1 : x > eps;
} 
double x[Mn], y[Mn], r[Mn];
int n;
vector<pair<double, int> > lst[Mn];
map<pair<double, int>, pair<double, int> > hsh[Mn];
inline void init() {
	for(int i = 0; i < Mn; ++i) {
		lst[i].clear();
		hsh[i].clear();
	}
}
inline double get_ang(int st, int ed) {
	return atan2(y[ed] - y[st], x[ed] - x[st]);
}
inline double sqr(double x) {
	return x * x;
}
inline double dis(int st, int ed) {
	return sqrt(sqr(x[ed] - x[st]) + sqr(y[ed] - y[st]));
}
inline double upd(double x) {
	if(dcmp(x + Pi) <= 0) {
		return x + 2 * Pi;
	}
	if(dcmp(x - Pi) > 0) {
		return x - 2 * Pi;
	}
	return x;
}
inline pair<double, double> calc(int st, int ed) {
	double ang = get_ang(st, ed);
	double a = r[st] + r[n];
	double b = r[ed] + r[n];
	double c = dis(st, ed);
	double delta = acos((sqr(a) + sqr(c) - sqr(b)) / (2 * a * c));	
	return make_pair(upd(ang + delta),upd(ang - delta));
}
inline int find(int k, pair<double, int> val) {
	for(int i = 0; i < lst[k].size(); ++i) {
		if(dcmp(lst[k][i].first - val.first) == 0 && lst[k][i].second == val.second) {
			return i;
		}
	}
}
inline double get_delta(double st, double ed) {
	double res = ed - st;
	if(dcmp(ed - st) < 0) {
		res += 2 * Pi;	
	}
	return res;
}
inline double solve(int st, pair<double, int> cur) {
	if(st == n)
		return 0;
	int pos = find(st, cur);
	int nxt = (pos + 1) % lst[st].size();
	if(nxt != pos)
		return get_delta(lst[st][pos].first, lst[st][nxt].first) * (r[st] + r[n]) + solve(lst[st][nxt].second, hsh[st][lst[st][nxt]]);
	else 
		return 2 * Pi * (r[st] + r[n]) + solve(lst[st][nxt].second, hsh[st][lst[st][nxt]]);
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		++n;
		for(int i = 1; i <= n; ++i) {
			scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
		}
		for(int i = 1; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(i != j) {
					if(dcmp(r[i] + r[j] + 2 * r[n] - dis(i, j)) > 0) {
						pair<double, double> tmp1 = calc(i, j);
						pair<double, double> tmp2 = calc(j, i);
						hsh[i][make_pair(tmp1.first, j)] = make_pair(tmp2.second, i);
						hsh[i][make_pair(tmp1.second, j)] = make_pair(tmp2.first, i);
						hsh[j][make_pair(tmp2.first, i)] = make_pair(tmp1.second, j);
						hsh[j][make_pair(tmp2.second, i)] = make_pair(tmp1.first, j);
						lst[i].push_back(make_pair(tmp1.first, j));
						lst[i].push_back(make_pair(tmp1.second, j));
						lst[j].push_back(make_pair(tmp2.first, i));
						lst[j].push_back(make_pair(tmp2.second, i));
					}
				}
			}
		}
		for(int i = 1; i < n; ++i) {
			if(dcmp(dis(i, n) - r[i] - r[n]) == 0) {
				lst[i].push_back(make_pair(get_ang(i, n), n));
				lst[n].push_back(make_pair(get_ang(n, i), i));
				//cerr << "find!" << endl;
				break;	
			}
		}
		for(int i = 1; i <= n; ++i) {
			sort(lst[i].begin(), lst[i].end());
		}
		double ans = solve(lst[n][0].second, make_pair(get_ang(lst[n][0].second, n), n));
		ans = ans / Pi * 180 / r[n];
		printf("%.10f\n", ans);
	}
	return 0;
}
