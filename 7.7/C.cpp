#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#define LL long long
using namespace std;

const int maxn=1010;
const int INF=199999999;

int a[maxn][maxn],flag[maxn][maxn];
int n;


bool in(int k,int c)
{
	int x,y;
	y=k%n-1;if(y<0)y+=n;
	x=(k-1)/n;
	if(x==c&&y>=c&&y<=n-1-c)return 1;
	if(x==n-1-c&&y>=c&&y<=n-1-c)return 1;
	if(x>=c&&x<=n-1-c&&y==c)return 1;
	if(x>=c&&x<=n-1-c&&y==n-1-c)return 1;
	return 0;
}

bool check(int c)
{
	int k,d,dd;
	int x,y,i,j,len=n-c-c-1;
	k=a[c][c];
	if(!in(k,c))return 0;
	y=k%n-1;if(y<0)y+=n;
	x=(k-1)/n;	
	if(x==c)d=y-c;
	else if(y==n-c-1)d=len+x-c;
	else if(x==n-c-1)d=2*len+n-c-1-y;
	else d=3*len+n-c-1-x;
	
	k=a[c][n-c-1];
	if(!in(k,c))return 0;
	y=k%n-1;if(y<0)y+=n;
	x=(k-1)/n;	
	if(y==n-c-1)dd=x-c;
	else if(x==n-c-1)dd=len+n-c-1-y;
	else if(y==c)dd=2*len+n-c-1-x;
	else dd=3*len+y-c;
	if(d!=dd)return 0;	
	
	k=a[n-c-1][n-c-1];
	if(!in(k,c))return 0;
	y=k%n-1;if(y<0)y+=n;
	x=(k-1)/n;	
	if(x==n-c-1)dd=n-c-1-y;
	else if(y==c)dd=len+n-c-1-x;
	else if(x==c)dd=2*len+y-c;
	else dd=3*len+x-c;	
	if(d!=dd)return 0;	
	
	k=a[n-c-1][c];
	if(!in(k,c))return 0;
	y=k%n-1;if(y<0)y+=n;
	x=(k-1)/n;	
	if(y==c)dd=n-c-1-x;
	else if(x==c)dd=len+y-c;
	else if(y==n-c-1)dd=2*len+x-c;
	else dd=3*len+n-c-1-y;	
	if(d!=dd)return 0;	
	
	//cout<<c<<' '<<d<<endl;
	
	for(j=c+1;j<n-1-c;++j)
	{
		k=a[c][j];
		if(!in(k,c))return 0;
		y=k%n-1;if(y<0)y+=n;
		x=(k-1)/n;
		if(x==c&&j<=y)dd=y-j;
		else if(x==c&&j>y)dd=(n-c-1-j)+(y-c)+3*len;
		else if(y==n-c-1)dd=n-c-j-1+x-c;
		else if(x==n-c-1)dd=n-c-1-j+len+n-c-1-y;//len+x-c+n-c-1-y;
		else dd=(n-c-1-j)+2*len+n-c-1-x;
		
		//cout<<x<<' '<<y<<' '<<dd<<endl;
		
		if(d!=dd)return 0;		
	}
	for(j=c+1;j<n-c-1;++j)
	{
		k=a[n-c-1][j];
		if(!in(k,c))return 0;
		y=k%n-1;if(y<0)y+=n;
		x=(k-1)/n;
		if(x==c)dd=j-c+len+y-c;
		else if(y==c)dd=j-c+n-c-1-x;
		else if(y==n-c-1)dd=j-c+2*len+x-c;
		else if(x==n-c-1&&y<=j)dd=j-y;
		else dd=3*len+j-c+n-c-1-y;
			//	cout<<x<<' '<<y<<' '<<' '<<n-c-1<<dd<<endl;
		if(d!=dd)return 0;		
	}
	for(i=c+1;i<n-c-1;++i)
	{
		k=a[i][c];
		if(!in(k,c))return 0;
		y=k%n-1;if(y<0)y+=n;
		x=(k-1)/n;
		if(x==c)dd=i-c+y-c;
		else if(y==n-c-1)dd=i-c+len+x-c;
		else if(x==n-c-1)dd=i-c+2*len+n-c-1-y;
		else if(y==c&&x<=i)dd=i-x;
		else dd=i-c+3*len+n-c-1-x;
			//	cout<<x<<' '<<y<<' '<<dd<<endl;
		if(d!=dd)return 0;	
	}
	for(i=c+1;i<n-c-1;++i)
	{
		k=a[i][n-c-1];
		if(!in(k,c))return 0;
		y=k%n-1;if(y<0)y+=n;
		x=(k-1)/n;
		if(x==n-c-1)dd=n-c-1-y+n-c-1-i;
		else if(y==c)dd=n-c-1-x+len+n-c-1-i;
		else if(x==c)dd=n-c-1-i+2*len+y-c;
		else if(y==n-c-1&&x>=i)dd=x-i;
		else dd=n-c-1-i+3*len+x-c;
			//	cout<<x<<' '<<y<<' '<<dd<<endl;
		if(d!=dd)return 0;
	}
	
	return 1;
	
	
} 


bool work()
{
	int i;
	for(i=0;i<(n+1)/2;++i) 
	if(!check(i))return 0;
	
	return 1;	
}

int main()
{
	cin>>n;
	int i,j;
	for(int t=1;;++t)
	{
		//memset(flag,0,sizeof(flag));
		if(n==0)break;
		for(i=0;i<n;++i) 
		for(j=0;j<n;++j)
		scanf("%d",&a[i][j]);
		if(work())printf("%d. YES\n",t);
		else printf("%d. NO\n",t);		
		cin>>n;	
		
		 
	}
    return 0;
}
/*

3
2 3 6
1 5 9
4 7 8

5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

2
1 2
3 4

2
1 3
2 4






*/
