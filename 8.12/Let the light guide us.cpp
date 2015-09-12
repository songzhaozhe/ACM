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
#define lc (o<<1)
#define rc ((o<<1)|1)
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=5010;
const int INF = 2e9;

int n,m;
int t[110][5010],f[110][5010];

int d[110][5010];
int ql, qr;
int v;
struct SegmentTree{
	int minn[maxn*4];
	int tag[maxn*4];
	
	void pushdown(int o,int L, int R)
	{
		if(L==R)return;
	//	if(tag[o]!=INF){
			tag[lc] = min(tag[lc],tag[o]);
			tag[rc] = min(tag[rc],tag[o]);
			minn[lc] = min(minn[lc],tag[lc]);
			minn[rc] = min(minn[rc],tag[rc]);				
			tag[o] = INF;
			minn[o] = min(minn[lc],minn[rc]);
	//	}
	}
	void modify(int o, int L, int R){
		if (ql <= L && qr >= R){
			tag[o] = min(tag[o], v);
			minn[o] = min(minn[o],tag[o]);
			return;			
		}
		int mid = (L+R)>>1;
		pushdown(o,L,R);
		if (ql <= mid){
			modify(lc, L, mid);
		}
		if (qr > mid){
			modify(rc, mid+1, R);
		}
		minn[o] = min(minn[lc],minn[rc]);
		return;		
	}
	
	int query(int o, int L, int R, int cur){
		int ret = min(tag[o],cur);
		if(ql <= L && qr >= R){
			return min(ret, minn[o]);
		}
		int mid = (L+R)>>1;
		if (ql <= mid){
			ret = query(lc,L,mid,ret);
		}
		if (qr > mid){
			ret =  query(rc, mid+1, R, ret);
		}
		return ret;
	}
	
	
}tree[110];

void init(){
	for (int i = 1; i <= n; ++i)
	//t[i].minn[1] = t[i].tag[1] = INF;
	{
		for (int j = 1; j < 4*m; ++j)
		tree[i].tag[j] = tree[i].minn[j] = INF;
		//memset(tree[i].tag,-1,sizeof(tree[i].tag));		
	}
}

int main()
{
	while(1){
		scanf("%d%d",&n, &m);
		if(n==0&&m==0)break;
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		scanf("%d",&t[i][j]);
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		scanf("%d",&f[i][j]);
		init();
		for (int i = 1; i <= m; ++i)
		{
			v = d[1][i] = t[1][i];
			ql = max(1, i - f[1][i]);
			qr = min(m, i + f[1][i]);
		//	cout<<ql<<' '<<qr<<endl;			
			tree[1].modify(1,1,m);
		//	cout<<v<<endl;
		}
		for (int i = 2; i <= n; ++i)//{
		for (int j = 1; j <= m; ++j)
		{
			ql = max(1, j - f[i][j]);
			qr = min(m, j + f[i][j]);
		//	cout<<ql<<' '<<qr<<endl;
			v = d[i][j] = tree[i-1].query(1,1,m,INF) + t[i][j];
			tree[i].modify(1,1,m);	
		//	cout<<v<<' ';		
		}
	//	cout<<endl;}
		int ans = INF;
		
		for (int j = 1; j <= m; ++j)
		ans = min(ans, d[n][j]);
		
		cout<<ans<<'\n';
		
	}
	
	return 0;
}


