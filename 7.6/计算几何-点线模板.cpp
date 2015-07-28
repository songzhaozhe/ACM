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

const int maxn=20010;
const int INF=199999999;

double eps=1e-8;
const double PI=acos(-1.);

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
ostream &operator <<(ostream &os,const Point& A){
		os<<'('<<A.x<<','<<A.y<<')';
		return os;
}
typedef Point Vector;
Vector operator +(Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator -(Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);} 
Vector operator *(Vector A,double p){return Vector(A.x*p,A.y*p);}
Vector operator /(Vector A,double p){return Vector(A.x/p,A.y/p);}
bool operator <(const Point& a,const Point& b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int dcmp(double x){if(fabs(x)<eps)return 0;else return x<0?-1:1;}
bool operator ==(const Point& a,const Point& b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y);}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);} 
Vector Rotate(Vector A,double rad) {return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}
Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;	
} 
double DistanceToLine(Point P,Point A,Point B){
	Vector v1=B-A,v2=P-A;
	return fabs(Cross(v1,v2))/Length(v1);
}
double DistanceToSegment(Point P,Point A,Point B){
	if(A==B)return Length(P-A);
	Vector v1=B-A,v2=P-A,v3=P-B;
	if(dcmp(Dot(v1,v2))<0)return Length(v2);
	else if(dcmp(Dot(v1,v3))>0)return Length(v3);
	else return fabs(Cross(v1,v2))/Length(v1);
}

int main()
{
	Point A(3,4),B(3,5);
	cout<<Length(A)<<endl; 
	
    return 0;
}

