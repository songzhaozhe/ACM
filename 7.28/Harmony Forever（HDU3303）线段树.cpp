#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int INF = 1e9;
const int maxn=5e5;
const int maxv = 5e5+10;

int ans[1010],num[1010],tim=0;
struct pii{
	int x,y;
};

pii smaller(const pii &a, const pii &b)
{
	if(a.x < b.x || (a.x==b.x && a.y > b.y))return a;
	else return b;
}

struct SegmentTree{
	pii minn[maxn*6];
	
	void init(){
		for ( int i = 0; i < maxn*6; ++i)
		minn[i].x = INF;
	}
	
	void modify(int o, int L, int R, int p){
		if(L == R){
			minn[o] = (pii){p, tim};
			return;			
		}
		int mid = L + (R - L) / 2;
		if(p <= mid){
			modify(o*2, L, mid,p);
		}
		if(p > mid){
			modify( o * 2 + 1, mid + 1, R, p);
		}
		minn[o] = smaller( minn[o*2+1], minn[o*2]);		
	}
	pii query(int o, int L, int R, int ql, int qr)
	{
		pii ret;
		ret.x = INF;
		if(ql <= L && qr >= R){
			return minn[o];
		}
		int mid = L + (R - L)/2;
		if(ql <= mid) ret = smaller(ret, query(o*2, L, mid, ql, qr));
		if(qr > mid) ret = smaller(ret, query( o*2 + 1, mid + 1, R, ql, qr));
		return ret;
	}	
}t;


void add(int x)
{
	tim++;
	for(int i = 1; i <= 1000; ++i)
	{
		int tmp = x % i;
		if(num[i] >= tmp||num[i]==-1){
			num[i] = tmp;
			ans[i] = tim;
		}
	}
	t.modify(1,1,maxv,x);
}

void work(int x)
{
	if(x<=1000)
	{
		printf("%d\n",ans[x]);
		return;
	}
	int k;
	pii ans;
	ans.x = INF;
//	cout<<"###"<<endl;
	if(x>maxv){
		pii tmp = t.query(1,1,maxv,1,maxv);
		ans = tmp;
	}
	else{
	for(k = 0; k * x < maxv; ++k)
	{
	//	cout<<k<<endl;
		pii tmp = t.query(1,1,maxv,k*x,k*x+x-1);
		if(tmp.x!=INF)tmp.x %= x;
	//cout<<k<<' '<<tmp.x<<' '<<tmp.y<<endl;
		ans = smaller ( ans, tmp);		
	}
	}
	if(ans.x == INF)printf("-1\n");
	else printf("%d\n",ans.y);	
}

char s [10];
int main()
{
	int T,cas=1,x;
	while(1)
	{
		//int cnt=0;
		memset(ans,0,sizeof(ans));
		memset(num,-1,sizeof(num));
		t.init();
		tim=0;
		scanf("%d",&T);
		if(T == 0)break;
		if(cas != 1)puts("");
		printf("Case %d:\n",cas);
		for ( int i = 1; i <= T; ++i)
		{
			scanf("%s",s);
			scanf("%d",&x);
			if(s[0]=='B')
			{
				add(x);
			//	++cnt;
			}
			else {
				if(tim==0)
				printf("-1\n");
				else
				work(x);
			}			
		}
		cas++;
	} 
	
	return 0;
}

/*
3
B 234324
B 32424
A 34423


*/
