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
const int maxn=1000005;
double eps = 1e-6;

vector<int> son[maxn];

struct circle{
	double x,y,r;
	int num,w;
	void read(){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		x=a;y=b;r=c;w=d;
	}
}C[maxn];

struct curve{
	int num;
	double x,y,left,r;
	int dir;
	bool in;	
};

vector<curve>cur;
multiset<curve> s;
int fa[maxn];
int tim;

bool cmp(const curve &a, const curve &b)
{
	if(a.left!=b.left)return a.left < b.left;
	return a.y < b.y;	
}

int main()
{
	int n;
	for(int i = 1; i <= n; ++i)
	{
		C[i].read();
		C[i].num = i;
		curve tmp1;
		tmp.num=i;
		tmp.x = C[i].x;
		tmp.y = C[i].y;
		tmp.r = C[i].r;
		tmp.left = C[i].x - C[i].r;
		tmp2 = tmp1;
		tmp2.y -= eps;
		tmp1.dir = 1;
		tmp1.in=1;
		tmp2.in=1;
		tmp2.dir = -1;
		cur.push_back(tmp1);
		cur.push_back(tmp2);
		tmp1.left = tmp1.x + tmp1.r;
		tmp2.left = tmp2.x + tmp2.r;
		tmp1.in=0;
		tmp2.in=0;
		cur.push_back(tmp1);
		cur.push_back(tmp2);						
	}
	sort(cur.begin(),cur.end(),cmp);
	for ( int i = 0; i < cur.size(); ++i)
	{
		curve &tmp = cur[i];
		if(!tmp.in){
			tmp.left = tmp.x - tmp.r;
			tmp.in = 1;
			s.erase(s.find(tmp));
			continue;		
		}
		tim = cur[i].left;
		set<curve>::iterator t = lowerbound(s.begin(),s.end(),tmp);
		
		
	}
	
	
	return 0;
}


