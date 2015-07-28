#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#define LL long long
using namespace std;

const int maxn=20;
const int INF=199999999;
const LL MOD = 1e9+7;

int n,r,k;
LL s[maxn],a[maxn];

struct matrix{
	
	
	
	LL a[10][10],n;
	
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
	matrix(int N,int x=1)
	{
		n=N;
		for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
		if(i == j) a[i][j] = x;
		else a[i][j] = 0; 
	}	


	
};

matrix operator +(const matrix &a, const matrix &b)
{
	matrix tmp(a.n,0);
	for(int i = 0; i < a.n; ++i)
	for(int j = 0; j < a.n; ++j)
	tmp.a[i][j]=(a.a[i][j]+b.a[i][j])%MOD,tmp.a[i][j]%=MOD;	
	return tmp;
}

matrix operator *(const matrix &a,const matrix &b)
{
	matrix tmp(a.n,0);
	for(int i = 0; i < a.n; ++i)
	for(int j = 0; j < a.n; ++j)
	for(int k = 0; k < a.n; ++k)
	tmp.a[i][j] += a.a[i][k] * b.a[k][j]%MOD, tmp.a[i][j] %= MOD;
	return tmp;
}

matrix exp(matrix m, int p)
{
	matrix ans(m.n,1);
	while(p)
	{
		if( p & 1)ans = ans * m;
		m = m * m;
		p>>=1;
	}
	return ans;
}

matrix expsum(matrix m, int p)
{
	if(p < 0)return matrix(m.n,0); 
	if(p == 0)return matrix(m.n,1);
	return expsum(m,(p-1)/2)*(matrix(m.n,1)+exp(m,(p-1)/2+1)) + ( (p % 2 == 0) ? exp( m, p): matrix(m.n, 0));
}

int main()
{
	int T,j;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d",&n,&r,&k);
		int i,last=0;
		LL ans=0;
		for( i = 1; i <= r; ++i)
		{
			scanf("%lld", &s[i]);

		}
		
		for( i = 1; i <= r; ++i)
		{
			scanf("%lld", & a[r - i + 1]);
			if(n==0)break;
			if((i) % k == 0){
				ans += s[i];
				ans %= MOD;
				last = i;
				--n;
			}
		}
		last += k;
	//	cout<<"last "<<last<<endl;
		matrix base( r, 1);
		matrix x( r, 1);
		for( i = 0; i < r; ++i)
		for( j = 0; j < r; ++j)
		{
			if( i == j + 1)x.a[i][j] = 1;
			else x.a[i][j] = 0;
			if( j == r - 1)x.a[i][j] = a[i+1];			
		} 
		
		for( i = 0; i < last-r; ++i)
		base = base * x;
			/*	
		for(int i=0;i<r;++i){
			for(int j=0;j<r;++j)
			cout<<base.a[i][j]<<' ';
			cout<<endl; 
		} 		*/
		matrix x1(x);
		for( i = 1; i < k; ++i){
			x1 = x1 * x;
		}
		
		
		
		matrix t = base * expsum( x1, n - 1);
		
		for( i = 0; i < r; ++i)
		{
			ans += s[i+1] * t.a[i][r-1]%MOD;
			//cout<<ans<<endl;
			ans %= MOD;
		}
		cout<<ans<<'\n';
		
		
	}
	
	
	
    return 0;
}
/*
3
4 5 3
1 1 2 3 5
1 1 0 0 0

313
*/
