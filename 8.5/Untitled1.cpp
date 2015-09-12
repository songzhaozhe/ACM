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

struct Point{
	int x,y;
	int d;
	int c;
	Point(int x=0,int y=0,int c = 'A', int d = 0):x(x),y(y),c(c),d(d){}	
	Point operator +(const Point &b){
		return Point(x+b.x,y+b.y,c,d);
	}
	
};
Point dir[]={Point(-1,0),Point(1,0),Point(0,-1),Point(0,-1)};

bool operator < (const Point a, const Point b){
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}


vector<Point>pos[200];

Point mm[50][50];
int n,m;

bool check1(const Point &a, const Point &b){
	if(a.x==b.x){
		for (int i = a.y+1; i < b.y; ++i)
		if(m[a.x][i].x!=-1)return 0;
		return 1;		
	}
	if(a.y==b.y){
		for (int i = a.x+1; i < b.x; ++i)
		if(m[i][a.y].x!=-1)return 0;
		return 1;
	}
	return 0;
}

bool check2(const Point &a, const Point &b){
	int flag = 1;
	for (int j = a.y+1;j <= b.y; ++j)
	if(m[a.x][j].x==-1){
		flag = 0;
		break;
	}
	for (int i = a.x+1; i < b.x; ++i)
	if(m[i][b.y].x==-1){
		flag = 0;
		break;
	}
	if(flag)return 1;
	for (int i = a.x+1; i < b.x; ++i)
	if(m[i][a.y].x==-1){
		return 0;
	}	
	for (int j = a.y+1;j <= b.y; ++j)
	if(m[b.x][j].x==-1){
		return 0;
	}
	return 1;
}
Point search1(Point x){
	int cur;
	int c = x.c;
	cur = pos[c].lower_bound(x)-pos[c].begin();
	for (int i = cur; i < pos[c].size(); ++i)
	{
		Point y = pos[c][i];
		if(!(x.x==y.x||x.y==y.y))continue;
		if(check1(x,y)){
			return y;
		}
	}
	return Point(-1,-1);
}

Point search2(Point x){
	int cur;
	int c = x.c;
	cur = pos[c].lower_bound(x)-pos[c].begin();
	for (int i = cur; i < pos[c].size(); ++i)
	{
		Point y = pos[c][i];
		if((x.x==y.x||x.y==y.y))continue;
		if(check2(x,y)){
			return y;
		}		
	}	
	return Point(-1,-1);	
}

void del(const Point &a, const Point &b){
	pos[a.c].erase(pos[a.c].lower_bound(a));
	pos[b.c].erase(pos[b.c].lower_bound(b));
	m[a.x][a.y] = Point(-1,-1);
	m[b.x][b.y] = Point(-1,-1);	
}

bool erase(){
	int flag = 0;
	//once
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		if(m[i][j].x!=-1){
			Point t = search1(m[i][j]);
			if(t.x!=-1){
				del(x,t);
				return 1;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		if(m[i][j].x!=-1){
			Point t = search2(m[i][j]);
			if(t.x!=-1){
				del(x,t);
				return 1;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		if(m[i][j].x!=-1){
			Point t = search3(m[i][j]);
			if(t.x!=-1){
				del(x,t);
				return 1;
			}
		}
	}
}

void maintain(){
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		if(m[i][j].x==-1)continue;
		Point t = m[i][j] + dir[m[i][j].d];
		if (m[t.x][t.y].x==-1){
			m[t.x][t.y] = t;
			vector<Point>::iterator it = pos[t.c].lower_bound(m[i][j]);
			*it.x = t.x;
			*it.y = t.y;
			m[i][j].x = m[i][j].y = -1;
			sort(pos[t.c].begin(),pos[t.c].end());
		}
	}
	
}

void solve(){
	int n;
	scanf("%d%d",&n,&m);
	char ch[5];
	
	for (i = 'A'; i <= 'Z'; ++i)
	pos[i].clear();
	
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	{
		Point t;
		scanf("%s",ch);
		t.x = i;
		t.y = j;
		t.c = ch[0];
		if(ch[1]=='U')t.r = 0;
		if(ch[1]=='D')t.r = 1;
		if(ch[1]=='L')t.r = 2;
		if(ch[1]=='R')t.r = 3;
		mm[i][j] = t;
		pos[ch[0]].push_back(t);		
	}
	for (int i = 0; i <= n+1; ++i)
	m[i][0].x = m[i][m+1].x = 200;
	for (int i = 0; i <= m+1; ++i)
	m[0][i].x = m[n+1][i].x = 200;
	
	
	while(erase())
	maintain();
	
	
}


int main()
{
	int cas,T;
	scanf("%d",&T);
	for (cas = 1; cas <= T; ++cas){
		printf("Case %d\n",solve());		
	}
	 
	return 0;
}


