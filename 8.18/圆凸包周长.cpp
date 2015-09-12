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
const double pi = acos(-1.); 

struct Point{
	double x, y;
	int id;
	Point(double x = 0, double y = 0,int id = 0):x(x),y(y),id(id){}
	
	Point operator - (const Point &b){
		return Point(x - b.x, y - b.y);
	}
	Point operator + (const Point &b){
		return Point(x + b.x, y + b.y); 
	}
	Point operator * (double a){
		return Point(x * a, y * a);
	}
	Point operator / (double a){
		return Point(x / a, y / a);
	}
	double len(){
		return sqrt(x*x+y*y);
	}	
};

double Cross(const Point & a, const Point &b){
	return a.x * b.y - a.y * b.x;
}

bool operator < (const Point a, const Point &b){
	if (a.x != b.x)return a.x < b.x;
	else return a.y < b.y; 
}

struct Circle{
	Point c;
	double r;
	Circle(Point c, double r):c(c),r(r){}
	Circle(){}
	Point getpoint(double a){
		return Point(c.x + cos(a)*r,c.y + sin(a)*r);
	}
	void read(){
		scanf("%lf%lf%lf", &c.x, &c.y, &r);
	}	
}c[510];

vector<Point> v;

int ConvexHull(vector<Point> & v, Point *ch){
	sort(v.begin(),v.end());
	int m = 0;
	int n = v.size();
	for (int i = 0; i < n; ++i){
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], v[i] - ch[m - 2]) <= 0) --m;
		ch[m++] = v[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i){
		while (m > k && Cross(ch[m-1] - ch[m-2], v[i] - ch[m-2]) <= 0) --m;
		ch[m++] = v[i]; 
	}
	if (n > 1) m--;
	return m;	
}
Point ch[500100];

double getarc(Point a, Point b, Point c,double r){
	Point v1 = a - c;
	Point v2 = b - c;
	double a1 = atan2(v1.y,v1.x);
	double a2 = atan2(v2.y,v2.x);
	double an = a2 - a1;
	if (an < 0)an = 2*pi + an;
	return r * an;
}


int main()
{
	int n;
	scanf("%d",&n);
	
	
	
	for (int i = 1; i <= n; ++i)
	{
		c[i].read();
		c[i].c.id = i;
	}
	if (n == 1){
		printf("%.9f\n",2*pi*c[1].r);
		return 0;
		
	}
	
	
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j < i; ++j)
	{
	//	if (i == j)continue;
		Circle a = c[i], b = c[j];
		if (a.r < b.r)swap(a,b);
		
		Point vec = b.c - a.c;
		double base = atan2(vec.y, vec.x);
		double an = acos((a.r - b.r)/ vec.len());
		Point tmp = a.getpoint(base + an);
		tmp.id = a.c.id;
		v.push_back(tmp);
		tmp = a.getpoint(base - an);
		tmp.id = a.c.id;
		v.push_back(tmp);
		
		vec = a.c - b.c;
		base = atan2(vec.y, vec.x);
		an = pi - an;
		tmp = b.getpoint(base + an);
		tmp.id = b.c.id;
		v.push_back(tmp);
		tmp = b.getpoint(base - an);
		tmp.id = b.c.id;
		v.push_back(tmp);		
	}
	int m = ConvexHull(v,ch);
	
	double ans = 0;
	for (int i = 0; i < m; ++i)
	{
		Point a = ch[i];
		Point b = ch[(i+1)%m];
		if (a.id == b.id)
			ans += getarc(a,b,c[a.id].c,c[a.id].r);
		else ans += (a - b).len();		
	}
	printf("%.9f\n",ans);
	
	
	return 0;
}
/*
4
0 0 1
3 3 1
3 0 1
0 3 1

*/


