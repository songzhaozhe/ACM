//#pragma comment(linker,"/STACK:10240000,10240000")
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
const int maxn=50003;

struct person{
	int a,l,id;
	int dfn,ldfn;	
}p[maxn];

int n,m;
vector<int> son[maxn];

int cnt;
int ans[maxn];
int ll[maxn],rr[maxn];

void dfs(int x)
{
	ll[x]= ++cnt;
	for (int i = 0; i < son[x].size(); ++i)
	{
		dfs(son[x][i]);		
	}
	rr[x]= cnt;
	return;	
}
bool operator < (const person &a, const person &b)
{
	return a.a>b.a;
}

struct SegmentTree{
	pair<int,int> maxx[2*maxn];
	
	void init(){
		for (int i = 0; i < 2*n; ++i)
		maxx[i] = make_pair(0,-1);
	}
	void modify(int o, int L, int R, int pos,pair<int,int> v)
	{
		if(L==R){
			maxx[o] = v;
			return;			
		}
		int mid = L + (R - L)/2;
		if (pos <= mid){
			modify(o*2,L,mid,pos,v);
		}
		if(pos > mid){
			modify(o*2 + 1, mid + 1, R, pos, v);
		}
		maxx[o] = max(maxx[o*2], maxx[o*2+1]);	
	}
	pair<int, int> query(int o, int L,int R, int ql, int qr)
	{
		if(ql<=L && qr>=R){
			return maxx[o];
		}
		pair<int,int> ret = make_pair(0,-1);
		int mid = L + (R - L)/2;
		if(ql <= mid)ret = max(ret,query(o*2, L,mid,ql,qr));
		if(qr > mid)ret = max(ret,query(o*2+1,mid+1,R,ql,qr));
		return ret;
		
	}	
}t;
int main()
{
	int T;
	scanf("%d",&T);
	p[0].a = -1;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 0; i <= n; ++i)
		son[i].clear();
		int fa;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d%d%d",&fa,&p[i].l,&p[i].a);
			p[i].id = i;
			son[fa].push_back(i);
		}
		t.init();
		cnt = 0;
		dfs(0);
		for(int i = 0; i < n; ++i)
		p[i].dfn = ll[i],p[i].ldfn = rr[i]; 
	//	return 0;
		sort(p, p + n);
		//reverse(p,p+n);
		for (int i = 0; i < n-1; ++i)
		{
			int j = i;
			ans[p[i].id] = t.query(1,1,cnt,p[i].dfn,p[i].ldfn).second;
			while(p[i].a==p[i+1].a){
				i++;
				ans[p[i].id] = t.query(1,1,cnt,p[i].dfn,p[i].ldfn).second;
			}
			for (;j <= i; ++j)
			t.modify(1,1,cnt,p[j].dfn,make_pair(p[j].l,p[j].id));			
		}	
		ans[p[n-1].id] = t.query(1,1,cnt,p[n-1].dfn,p[n-1].ldfn).second;
		//cout<<p[n-1].dfn<<' '<<p[n-1].ldfn<<endl;
		int x;
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d",&x);
			printf("%d\n",ans[x]);		
		}
	}
	
	return 0;
}


