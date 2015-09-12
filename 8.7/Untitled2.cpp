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
const int maxn=1005;
const double pi = acos(-1.0);

const double eps = 1e-8;

int dcmp(double x){
	return x < eps ? -1 : x > eps;
}

struct Point{
	double x,y,r;
	void read(){
		scanf("%lf%lf%lf",&x,&y,&r);
	}
	Point(double x = 0, double y = 0, double r):x(x),y(y),r(r){}
		
	Point operator - (const Point &b){
		return Point(x - b.x, y - b.y, z - b.z);
	}
	double len(){
		return sqrt(x*x+y*y);
	}
	
};

Point p[maxn];
vector<pair<double,int> > v[maxn];

int findnext(int k,double cur)
{
	int i;
	for (i = 0; i < v[k].size(); ++i)
	{
		if(dcmp(v[k][i].first-cur)==0)
		break;		
	}
	i++;
	i%=v[k].size();
	return v[k][i].second();
}

double solve(){
	for (int i = 0; i < maxn; ++i)
	v[i].clear();
	int s;
	for (int i = 1; i <= n; ++i)
	if( dcmp((p[0]-p[i]).len-p[0].r-p[i].r)==0){
		s = i;
		break;
	}
	double r = p[0].r;
	double angle = atan2((p[0]-p[s]).y, (p[0]-p[s]).x);
	v[start].push_back(make_pair(angle, -1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j){
			if(i==j)continue;
			if(dcmp(p[i].r+p[j].r+r+r-(p[i]-p[j]).len()) >= 0)continue;
			
			double base = atan2((p[j] - p[i]).y, (p[j] - p[i]).x);
			double a,b,c,an;
			a = (p[i]-p[j]).len();
			b = p[i].r + r;
			c = p[j].r + r;
			an = acos( (a*a + b*b - c*c)/2/a/b)
			v[i].push_back(make_pair( base + an, j));			
		}
		v[i].sort();
		reverse(v[i].begin(),v[i].end());
	}
	double ret = 0;
	int u = s;
	double cur = angle;
	int tmp;
	tmp = findnext(u,cur);
	ret += p[u].r * 
	while(
	
	
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i)
		p[i].read();
		p[0].read();
		double ans = solve();
		ans = ans / p[0].r * 180 / pi;		
	}
	
	
	return 0;
}


