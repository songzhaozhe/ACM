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

struct Point {
	int x,y;
	int r;
	Point(int x = 0, int y = 0,int r = 0):x(x),y(y),r(r){	}
	void read(){
		scanf("%d%d%d",&x,&y,&r);
	}

	Point operator - (const Point &b)const{
		return Point(x-b.x,y-b.y,r);
	}
	Point operator + (const Point &b)const{
		return Point(x-b.x,y-b.y,r);
	}	
};

int cross(Point A, Point B){
	return A.x*B.y-A.y*B.x;
}

bool operator < (Point A,Point B){
	return cross(A,B)<0;
}

int n;

Point p[maxn];

int work(int k){
	int rear = 0;
	vector<Point>v;
	for (int i = 0; i < n; ++i)
	{
		if(i==k)continue;
		Point tmp = p[i]-p[k];
		if(tmp.y<0||(tmp.y==0&&tmp.x<0)){
			tmp.y*=-1;
			tmp.x*=-1;
			tmp.r^=1;
		}
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	int cnt = v.size();
	//cout<<cnt<<"###"<<endl;
	int w = 0,b = 0,num[2] = {0};
	for (int i = 0; i < cnt; ++i)
	if(v[i].r)b++;
//	cout<<b<<"@@@"<<endl;
	int ans = max(b,cnt-b);
	for (int i = 0; i < cnt; ++i)
	{
		//b -= num[1];
		w += num[0];
		num[1] = num[0] = 0;
		num[v[i].r]++;
		while(i<cnt-1&&cross(v[i],v[i+1])==0)
		{
			++i;
			num[v[i].r]++;			
		}
		b -=num[1];
		
		ans = max(ans, b + w + num[1]+num[0]);
		ans = max(cnt-b-w,ans);
	//	num[1] = num[2] = 0;
	//	cout<<i<<' '<<' '<<b<<' '<<b + w + num[1]+num[2]<<' '<<cnt-b-w<<' '<<ans<<endl;
	}
	return ans;
	
}


int main()
{
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for (int i = 0; i < n; ++i)
		{
			p[i].read();
		}
			
			
		int ans = 0;
		
		for (int i = 0; i < n; ++i)
		ans = max(ans,work(i));
		
		printf("%d\n",ans+1);
		
		
		
	}
	
	
	return 0;
}


