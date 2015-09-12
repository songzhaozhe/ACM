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
Point dir[]={Point(-1,0),Point(1,0),Point(0,-1),Point(0,1),Point(0,0)};

bool operator < (const Point a, const Point b){
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}

Point mm[50][50];
int n,m;

void del(const Point &a, const Point &b){
	//cout<<"del"<<a.x<<' '<<a.y<<' '<<b.x<<' '<<b.y<<endl;
	mm[a.x][a.y] = Point(-1,-1);
	mm[b.x][b.y] = Point(-1,-1);	
}

void extend(Point x,int c, vector<Point> &v, vector<Point>&ans,int vis[][31]){
	for (int i = 0; i < 4; ++i)
	{
		Point t = x;
		Point next = t + dir[i];		
		while(next.x>=0&&next.y>=0&&next.x<=n+1&&next.y<=m+1&&mm[next.x][next.y].x==-1&&!vis[next.x][next.y]){
			v.push_back(next);
			vis[next.x][next.y] = 1;
			next = next + dir[i];			
		}
		if (next.x<0||next.y<0||next.x>n+1||next.y>m+1||vis[next.x][next.y])continue;
		if(mm[next.x][next.y].c == c){
			ans.push_back(mm[next.x][next.y]);
		}		
	}
	sort(ans.begin(),ans.end());
	
}

bool erase(){
	//cout<<"haha"<<endl;
	int flag = 0;
	vector<Point>v[31][31][4]; 
	vector<Point>ans;
	//cout<<"@@"<<endl;
	int vis[31][31][31][31]={0};
//	memset(vis,0,sizeof(vis));
	//cout<<"##"<<endl;
	//once
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	vis[i][j][i][j]=1;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		if(mm[i][j].x!=-1){
			extend(mm[i][j],mm[i][j].c,v[i][j][1],ans,vis[i][j]);
			if(ans.size()!=0){
			//	cout<<"###"<<i<<' '<<j<<endl;
				del(mm[i][j],ans[0]);
				return 1;
			}			
		}
	}
	
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		if(mm[i][j].x!=-1){
			for (int k = 0; k < v[i][j][1].size(); ++k)
			{
				Point &x = v[i][j][1][k];
				extend(x,mm[i][j].c,v[i][j][2],ans,vis[i][j]);				
			}
			if(ans.size()!=0){
				del(mm[i][j],ans[0]);
				return 1;
			}	
		}
	}
	
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		if(mm[i][j].x!=-1){
			for (int k = 0; k < v[i][j][2].size(); ++k)
			{
				Point &x = v[i][j][2][k];
				extend(x,mm[i][j].c,v[i][j][3],ans,vis[i][j]);			
			}
			if(ans.size()!=0){
				del(mm[i][j],ans[0]);
				return 1;
			}				
		}
	}
	return 0;
}

bool maintain(){
	bool flag = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		if(mm[i][j].x==-1)continue;
		Point t = mm[i][j] + dir[mm[i][j].d];
		if (t.x>0&&t.y>0&&t.x<=n&&t.y<=m&&mm[t.x][t.y].x==-1){
			flag = 1;
			mm[t.x][t.y] = t;
			mm[i][j].x = mm[i][j].y = -1;
		}
	}
	return flag;
}

void draw(){
	char ans[35];
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		if(mm[i][j].x==-1){
			ans[j-1] = '.';
			//putchar('.');
			//printf(".   ");
		}else{
			ans[j-1] = mm[i][j].c;
		//	putchar(mm[i][j].c);
		//	printf("%c%d%d ",mm[i][j].c,mm[i][j].x,mm[i][j].y);
		}
		ans[m] = '\0';
		
		puts(ans);
	}
//	puts("");
	
	
}

void solve(){
	char ch[5];	
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		Point t;
		scanf("%s",ch);
		t.x = i;
		t.y = j;
		t.c = ch[0];
		if(ch[1]=='U')t.d = 0;
		if(ch[1]=='D')t.d = 1;
		if(ch[1]=='L')t.d = 2;
		if(ch[1]=='R')t.d = 3;
		if(ch[1]=='S')t.d = 4;
		mm[i][j] = t;		
	}
	for (int i = 0; i <= n+1; ++i)
	mm[i][0].x = mm[i][m+1].x = -1;
	for (int i = 0; i <= m+1; ++i)
	mm[0][i].x = mm[n+1][i].x = -1;
	
	//cout<<"begin"<<endl;
	while(erase())
	{
//	draw();
	while(maintain());
//	cout<<"maintain"<<endl;draw();
	}
//	cout<<"###"<<endl;
	draw();
	
	
}


int main()
{
	int cas,T;
	//scanf("%d",&T);
	for (cas = 1;; ++cas){
		scanf("%d%d",&n,&m);
		if(n==0)break;
		printf("Case %d:\n",cas);
		solve();		
	}
	 
	return 0;
}


