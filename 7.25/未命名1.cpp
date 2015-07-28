#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

const LL INF=3e18;

int pr[100],tot;
pair<int, int> lst[100][100];
int cnt[100];
inline bool isprime(int x) {
	if(x == 1)
		return false;
	for(int i = 2; i < x; ++i)
		if(x % i == 0)
			return false;
	return true;
}
inline void dfs(int pos, int val, int sign, int lim) {
	if(val > 100)
		return;
	if(pos == tot + 1 || pr[pos] > lim) {
		return;
	}
	dfs(pos + 1, val, sign, lim);
	dfs(pos + 1, val * pr[pos], -sign, lim);
	if(val * pr[pos] <= 100) {
		++cnt[lim];
		//cerr << val * pr[pos] << endl;
		lst[lim][cnt[lim]] = make_pair(val * pr[pos], -sign);
	}
}
inline void init() {
	for(int i = 1; i <= 63; ++i) {
		if(isprime(i)) {
			pr[++tot] = i;
		}
	} 
	for(int lim = 2; lim <= 62; ++lim) {
		dfs(1, 1, -1, lim);
		sort(lst[lim] + 1, lst[lim] + cnt[lim] + 1);
		//printf("%d %d\n",lim, cnt[lim]);
	}
}

unsigned long long n;
int R;

LL exp(LL x,LL m)
{
	LL ret=x;
	LL ans=1;
	LL mm=m;
	while(m>0)
	{
		if(m&1){
			if(INF/ret<ans)return INF;
			else ans*=ret;
		}
		m>>=1;
		if(INF/ret<ret)return INF;
		else ret*=ret;
	}
	//cout<<"####"<<x<<' '<<mm<<' '<<ans<<endl;
	return ans;
}


unsigned long long calc(unsigned long long val) {
	unsigned long long res(0);
	unsigned long long l = 1;
	unsigned long long r = sqrt(1.0 * val) + 100;
	LL mid;
	for(int i = 1; i <= cnt[R]; ++i) {
		while(l<r-1)
		{
			mid=l+(r-l)/2;
			if(exp(lst[R][i].first,mid)>val)
			r=mid;
			else l=mid;
		}
		
		
	//	l=(LL)pow(val,1./lst[R][i].first);
//	cout<<val<<' '<<l<<' '<<lst[R][i].first<<endl; 
		r=l+1;
		res += (l - 1) * lst[R][i].second;
		l=1;
		if(r==2)break;
	}
	return val - res - 1;
}
char cc;
void read(unsigned long long &x){
	for	(cc=getchar();cc<'0' || cc>'9';cc=getchar());
	for	(x=0;cc>='0' && cc<='9';cc=getchar())	x=((x<<3)+x+x)+cc-'0';
}

void read(int &x){
	for	(cc=getchar();cc<'0' || cc>'9';cc=getchar());
	for	(x=0;cc>='0' && cc<='9';cc=getchar())	x=((x<<3)+x+x)+cc-'0';
}
int main() {
	init();
	int T;
	scanf("%d", &T);
	while(T--) {
		read(n);read(R);
		LL now = n;
		while (1)
		{
			LL ans = calc(now);
			if (ans == n)
				break;
			now += n - ans;
			if (n - ans < 0)
				return 0;
		}

		
		printf("%I64d\n",now);
	}
	return 0;
}
/*
14 
2000000000000000000 62
 2000000000000000000 62
2000000000000 62
20 62
2 62
2000000000000000 62
200000000 62
20000000000 62
2000000000000000000 62
 200000000 62
200000000 62

*/ 
 
