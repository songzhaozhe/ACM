#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=3e5 + 10;
const int INF = 1e9 + 5;


vector<int> own[maxn];
int cur[maxn];
int tmp[maxn];
int l[maxn],r[maxn],a[maxn];
long long tree[maxn];
int ans[maxn],p[maxn];
int n,m,k;

inline int lowbit(int x){
	return x & (-x);
}

void Add (int v, int p){
	while (p > 0){
		tree[p] += v;
		p -= lowbit(p);		
	}
}

void add (int l, int r, int v){
//	cout<<"add"<<v<<' '<<l<<' '<<r<<endl;
	Add(v,r);
	Add(-v,l-1);	
}

int query(int p){
	long long ret = 0;
	while (p <= m){
		ret = min((long long)INF, tree[p] + ret);
		p += lowbit(p);		
	}
	return (int)ret;
}

void solve(vector<int> &v, int L, int R){
//	cout<<R<<' '<<L<<endl;
	if (R - L < 0){
		for (int i = 0; i < v.size(); ++i)
		ans[v[i]] = L;
		return;		
	}
	int mid = L+R>>1;
	for (int i = L; i <= mid; ++i)
	{
		if (l[i] <= r[i]){
			add(l[i],r[i],a[i]);
		}else{
			add(l[i],m,a[i]);
			add(1,r[i],a[i]);			
		}		
	}
	vector<int> v1,v2;
//	for (int i = 1; i <= m; ++i)
//	cout<<i<<' '<<query(i)<<endl;
	
	for (int i = 0; i < v.size(); ++i)
	{
		int x = v[i];
		tmp[x] = 0;
		for (int j = 0; j < own[x].size(); ++j)
		{
			tmp[x] = min(INF,tmp[x] + query(own[x][j]));			
		}
	//	cout<<x<<' '<<tmp[x]<<endl;
		if (tmp[x] + cur[x] >= p[x]){
			v1.push_back(x);
		}else{
			cur[x] += tmp[x];
			v2.push_back(x);
		}		
	}
	for (int i = L; i <= mid; ++i)
	{
		if (l[i] <= r[i]){
			add(l[i],r[i],-a[i]);
		}else{
			add(l[i],m,-a[i]);
			add(1,r[i],-a[i]);			
		}		
	}	

	if(v1.size()>0)solve(v1,L,mid-1);
	if(v2.size()>0)solve(v2,mid+1,R);
	
}


int main()
{
	scanf("%d%d",&n,&m);
	int x;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d",&x);
		own[x].push_back(i);
	}
	vector<int> v;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&p[i]);
		v.push_back(i);
	}
	scanf("%d",&k);
	for (int i = 1; i <= k; ++i)
	scanf("%d%d%d",&l[i],&r[i],&a[i]);
	
//	cout<<k<<endl;
	solve(v,1,k+1);
	
	for (int i = 1; i <= n; ++i)
	if (ans[i] >= k+1)printf("NIE\n");
	else printf("%d\n",ans[i]);
	
	
	
	return 0;
}
/*
1 1
1
10
5
1 1 4
1 1 5
1 1 3
1 1 3
1 1 1


*/

