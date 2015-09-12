#include<iostream>
#include<cstdlib>
#include<cmath>
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
	int w;
	int left;	
	void read(){
		scanf("%d%d%d%d",&x,&y,&r,&w);
		left = x - r;
	}	
	bool contain(const circle &c) {
		return r > c.r && (r - c.r) * (r - c.r) > (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y);
	}
	double up(int cur){
		return (double)y + sqrt(sqr(r) - sqr(cur - x));
	}
	double down(int  cur){
		return (double)y - sqrt(sqr(r) - sqr(cur - x));
	}
}cir[maxn];

bool operator < (const circle &a, const circle &b) {
	return a.r > b.r;
}

struct circmp{
	int id;
	circmp(int id = 0):id(id){}	
	int rid()const{
		if(id>0)return id;
		else return -id;
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
int maxx[maxn];

int work(int n)
{
	int ans = cir[n].w;
	int tmp = 0;
	for (int i = 0; i < son[n].size(); ++i)
	{
	//	cout<<n<<' '<<son[n][i]<<endl;
		tmp += maxx[son[n][i]];		
	}
	maxx[n] = max(tmp,ans);
//	cout<<n<<' '<<"###"<<maxx[n]<<endl;
}
vector <pair<int,int> > e;
set<circmp>s;
int q[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	cir[i].read();
	
	
	//sort(cir+1,cir+n+1);
	for( int i = 1; i <= n; ++i)
	{
		e.push_back(make_pair(cir[i].x - cir[i].r, i));
		e.push_back(make_pair(cir[i].x + cir[i].r, -i));
	}
	sort(e.begin(),e.end());

	for (int i = 0; i < e.size(); ++i)
	{
		cur = e[i].first;
		if (e[i].second > 0){
			int id = e[i].second;
			set<circmp>::iterator t = s.lower_bound(circmp(id));
			if(t == s.end())
			{
				fa[id] = 0;
				son[0].push_back(id);
			}else{		
				int nid = (*t).id;
				if (nid > 0){
					fa[id] = nid;
					son[nid].push_back(id);
				}else{
					fa[id] = fa[-nid];
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
	
	int rear = -1,front = 0;
	q[++rear] = 0;
	while(front <= rear)
	{
		int x = q[front++];
	//	cout<<x<<endl;
		for (int i = 0; i < son[x].size(); ++i)
		{
			q[++rear] = son[x][i];
		}
	}
	for (int i = rear; i >= 0; --i)
		work(q[i]);
	
	cout<<maxx[0]<<endl;
	
	
	
	
	return 0;
}
/*
3
0 0 100 4
1 1 50 5
2 3 10 1




*/


