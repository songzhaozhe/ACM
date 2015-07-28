#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<sstream>
#include<algorithm> 
#include<vector>
using namespace std;

const int maxn=1000010;
const int INF=199999999;

double eps=1e-8;
const double PI=acos(-1.);

struct Point{
	int x,y;
	Point(int x=0,int y=0):x(x),y(y){}
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
int Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
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

Point p[maxn];
double a[maxn];
int rear;

int work()
{
	if(rear==0)return 1;
	if(rear==1)return 2;
	
	int i,j,k,maxx=1,cur;
	for(i=0;i<=rear;++i)
	for(j=i+1;j<=rear;++j)
	{
		cur=2;
		for(k=j+1;k<=rear;++k)
		{
			if(Cross(p[i]-p[j],p[i]-p[k])==0)
			{
				++cur;	
				///cout<<i<<' '<<j<<' '<<k<<endl;
				//cout<<Cross(p[i]-p[j],p[i]-p[k])<<endl;
			}
		}
		//cout<<cur<<endl;
		maxx=max(maxx,cur);
	} 
	return maxx;
	

}

int main()
{
	int i;
	char s[maxn];
	int  x,y;
	for(i=1;;++i)
	{
		rear=-1;
		gets(s);
		if(s[0]=='-'&&s[1]=='-')break;
		while(!(s[0]=='-'&&s[1]=='-'))
		{			
		//	stringstream ss(s);
			sscanf(s,"%d%d",&x,&y);
			//ss>>x>>y;
			//cout<<x<<y<<endl;
			p[++rear].x=x;
			p[rear].y=y;		
			gets(s);
		}
		cout<<i<<". "<<work()<<'\n';
	}
	
	
	
    return 0;
}

