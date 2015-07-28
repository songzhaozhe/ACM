#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
using namespace std;

const int maxn=20100;
const int INF=199999999;
double limit=200000;

double x1,yy1,x2,y2;
double eps=1e-8;
const double PI=acos(-1.);

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	
	
};

Point A,B;

ostream &operator <<(ostream &os,const Point& A){
		os<<'('<<A.x<<','<<A.y<<')';
		return os;
}
typedef Point Vector;

Vector operator +(Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);} 

Vector operator -(Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);} 

Vector operator *(Vector A,double p){return Vector(A.x*p,A.y*p);}

double Cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}

double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}

Vector Rotate(Vector A,double rad)
{
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

Point get(Point P,Vector v,Point Q,Vector w){
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;	
} 



double ok(Point P) {
	double anglea = atan2(A.y, A.x - P.x);
	double angleb = atan2(B.y, B.x - P.x);
	
	double ret = angleb - anglea;
	
	for (; ret < eps; ret += 2 * PI);
	for (; ret > 2 * PI + eps; ret -= 2 * PI);
	
	return (ret > PI + eps) ? (2 * PI - ret) : ret;
}
int main()
{
	cin>>x1>>yy1>>x2>>y2;
	if(yy1*y2<eps){
		cout<<"3.141593"<<endl;
		return 0;
	}
	
	A.x=x1;
	A.y=yy1;
	B.x=x2;
	B.y=y2;
	
	Vector a(1.0*(x2-x1),1.0*(y2-yy1));
	Point O(0,0);
	Vector x(1,0);
	
	Point I;
	//if(abs(yy1-y2)>eps)
	I=get(A,a,O,x);
	//else I.x=(x1+x2)/2;
	cout<<I<<endl;
	int re=1;
	double l=I.x,r=limit,mid1,mid2;
	while((re++)<maxn)
	{
		mid1 = (2 * l + r) / 3;
		mid2 = (l + 2 * r) / 3;
		
		//mid1=(r-l)/2+l;
		//mid2=(r-mid1)/2+mid1;
		Point P1(mid1,0),P2(mid2,0);
		if(ok(P1)<=ok(P2))l=mid1;
		else r=mid2;
	} 
	Point P1(l,0);
	double ans=ok(P1);
	
	re=1;
	l=-limit;r=I.x;mid1;mid2;
	while((re++)<maxn)
	{
		mid1 = (2 * l + r) / 3;
		mid2 = (l + 2 * r) / 3;
		//mid1=(r-l)/2+l;
		//mid2=(r-mid1)/2+mid1;
		Point P1(mid1,0),P2(mid2,0);
		if(ok(P1)<=ok(P2))l=mid1;
		else r=mid2;
	} 
	P1.x=l;
	ans=max(ans,ok(P1)); 
	
	printf("%.6lf\n",ans);
	
	
	
	
	
	/*
	yy1=abs(yy1);
	y2=abs(y2);
	
	Point mid(1.0*(x1+x2)/2,1.0*(yy1+y2)/2);
	Point A(x1,yy1),B(x2,y2);
	
	Vector a(1.0*(x2-x1),1.0*(y2-yy1));
	cout<<a<<endl;
	Vector b=Rotate(a,PI/2);
	cout<<b<<endl;
	Point O(0,0);
	Vector x(1,0);
	
	Point I=get(mid,b,O,x);
	cout<<I<<endl;*/
	
	
	
    return 0;
}

