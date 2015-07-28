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

const int M = 400;

int m, k;
pair<long long, long long> f[M + 5][M + 5];

long long gcd(long long x, long long y) {
	x = abs(x), y = abs(y);
	for (; y; ) {
		x %= y;
		swap(x, y);
	}
	return x;
}

void divide(pair<long long, long long> &num) {
	long long divisor = gcd(num.first, num.second);
	num.first /= divisor;
	num.second /= divisor;
}

void prepare() {
	f[0][1] = make_pair(1, 1);
	f[1][1] = make_pair(1, 2);
	f[1][2] = make_pair(1, 2);
	
	for (int i = 2; i <= M; ++i) {
		for (int j = i + 1; j > 1; --j) {
			f[i][j].first = i * f[i - 1][j - 1].first;
			f[i][j].second = j * f[i - 1][j - 1].second;
			divide(f[i][j]);
		}
		
		pair<long long, long long> sum = make_pair(0, 1);
		for (int j = i + 1; j > 1; --j) {
			sum.first = sum.first * f[i][j].second + sum.second * f[i][j].first;
			sum.second = sum.second * f[i][j].second;
			divide(sum);
		}
		
		f[i][1] = make_pair(sum.second - sum.first, sum.second);
		divide(f[i][1]);
	}
}

void solve() {
	scanf("%d%d", &m, &k);
	if (f[m][k].first == 0) {
		cout << 0 << endl;
	} else if (f[m][k].second == 1) {
		cout << f[m][k].first << endl;
	} else {
		cout << f[m][k].first << "/" << f[m][k].second << endl;
	}
}

int main() {
	prepare();	
	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; ++i) {
		scanf("%*d");
		printf("%d ", i);
		solve();
	}
	return 0;
}
/*
5
1 4 5
2 6 7
3 8 4
4 100 50
5 60 30
*/


