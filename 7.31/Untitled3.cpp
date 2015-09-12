#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=5e5;

int cur;

inline LL sqr(LL x)
{
	return x*x;
}

struct circle{
	int x,y,r;
	int left;	
	void read(){
		scanf("%d%d%d",&x,&y,&r);
		left = x - r;
	}	
	double up(int cur){
		return (double)y + sqrt(sqr(r) - sqr(cur - x));
	}
	double down(int  cur){
		return (double)y - sqrt(sqr(r) - sqr(cur - x));
	}
	
	bool contain(const circle &c) {
		return r > c.r && (r - c.r) * (r - c.r) > (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y);
	}
	
	
}cir[maxn];

bool operator < (const circle &a, const circle &b) {
	return a.r > b.r;
}

struct circmp{
	int id;
	circmp(int id = 0):id(id){}	
	int rid()const{
		return abs(id);
	}
	double getp(int cur)const
	{
		return id > 0 ? cir[id].up(cur):cir[-id].down(cur);
	}
};

bool operator < (const circmp &a, const circmp &b)
{
	if (a.rid()==b.rid()){
		return a.id < b.id;
	}
	return a.getp(cur) < b.getp(cur);
}

int fa[maxn];
vector<int>son[maxn];

vector <pair<int,int> > e;
set<circmp>s;
int q[maxn];

int sg(int u) {
	int ret = 0;
	for (int i = 0; i < (int)son[u].size(); ++i) {
		ret ^= sg(son[u][i]);
	}
	return ret + 1;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		cir[i].read();
		son[i].clear();
	}
	son[0].clear();
	
	sort(cir+1,cir+n+1);
	e.clear();
	for( int i = 1; i <= n; ++i)
	{
		e.push_back(make_pair(cir[i].left,i));
		e.push_back(make_pair(cir[i].x + cir[i].r, -i));
	}
	sort(e.begin(),e.end());
	s.clear();
	for (int i = 0; i < e.size(); ++i)
	{
		cur = e[i].first;
		if (e[i].second > 0){
			int id = e[i].second;
			set<circmp>::iterator t = s.lower_bound(circmp(id));
			if(t == s.end())
			{
				fa[id] = 0;
				//son[0].push_back(id);
			}else{				
				int nid = (*t).id;
				if (cir[nid].contain(cir[id])){
					fa[id] = nid;
				//	son[id].clear();
					son[nid].push_back(id);
				}else{
					fa[id] = fa[nid];
				//	son[id].clear();
					son[fa[id]].push_back(id);
				}
			}
			s.insert(circmp(id));
			s.insert(circmp(-id));			
		}else{
			int id = -e[i].second;
			s.erase(circmp(id));
			s.erase(circmp(-id));
		}
	}
//	memset(maxx,-1,sizeof(maxx));
	
//	dfs(0);
	
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (fa[i] == 0) {
				ans ^= sg(i);
			}
		}
		puts(ans ? "Alice" : "Bob");
	
}
	
	return 0;
}
/*
3

4 3 2 3

4 6 10 5

3 9 1 4

*/


