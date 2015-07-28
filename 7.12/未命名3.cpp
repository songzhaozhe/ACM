#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const long long MOD = 1e9 + 7;
struct matrix{
	long long a[10][10];
	int n;
	
	matrix (const matrix &b) {
	n = b.n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = b.a[i][j];
	}
	matrix(int N, int x) {
	 	n = N;
	 	memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
				if (i == j) a[i][j] = x;
	}
	matrix (const matrix &b) {
		n = b.n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = b.a[i][j];
	}
	matrix& operator =(const matrix &b) {
		if (this == &b) return *this;
		n = b.n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = b.a[i][j];
		return *this;
	}
	matrix operator +(const matrix &b) {
		matrix ret(n, 0);
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) {
				ret.a[i][j] = (a[i][j] + b.a[i][j]) % MOD;
			}
		return ret;
	}
	matrix operator *(const matrix &b) {
		matrix ret(n, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
				for (int k = 0; k < n; k++)
				ret.a[i][j] = (ret.a[i][j] + a[i][k] * b.a[k][j] % MOD) % MOD;
		return ret;
	}
};
int T, n, r, k, last;
long long ans;
long long a[10], s[10];
matrix powe(matrix m, int b) {
	matrix ret(r, 1);
	while (b) {
		if (b & 1) ret = ret * m;
		m = m * m;
		b >>= 1;
	}
	return ret;
}
matrix spowe(matrix m, int b) {
	if (b < 0) return matrix(r, 0);
	if (b == 0) return matrix(r, 1);
	return spowe(m, (b - 1) / 2) * (matrix(r, 1) + powe(m, (b - 1) / 2 + 1)) + ((b % 2 == 0) ? powe(m, b): matrix(r, 0));
}
int main() {
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d%d%d", &n, &r, &k);
		for (int i = 1; i <= r; i++)
			scanf("%lld", &s[i]);
		last = 0;
		for (int i = 1; i <= r; i++) {
			scanf("%lld", &a[i]);		
			if (n == 0) break;
			if (i % k == 0) {
				last = i;
				ans = (ans + s[i]) % MOD;
				n--;
			}
		}
		last += k;
		matrix x(r, 0);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				if (j == r - 1) {
					x.a[i][j] = a[r - i];
				} else {
					if (i == j + 1) x.a[i][j] = 1; else x.a[i][j] = 0;
				}
			} 
		}
		matrix ba(r, 1), x1(x);
		for (int i = 1; i <= last - r; i++) ba = ba * x1; 
		for (int i = 1; i < k; i++) x = x * x1;
		matrix t = ba * spowe(x, n - 1);
		for (int i = 0; i < r; i++) {
			ans = (ans + s[i + 1] * t.a[i][r - 1] % MOD) % MOD;
		}
		printf("%d\n", (int)ans);	
	}	
	return 0;		
}
