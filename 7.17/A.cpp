#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=1e5+100;
const int INF=199999999;


int n,x,y,h1,h2;
int a[maxn],b[maxn];
int tong[10001];
int minn;

bool check(int n)
{
	int i;
	int me=h1,you=h2;
	for(i=1;i<=n;++i)
	b[i]=a[i];
	int damage=b[minn];
	int cnt=0;
	sort(b+1,b+n);
	for(i=1;i<=n-1;++i)
		{
			//if(cnt==minn-1)return 1;
			if(me-b[i]<=0)
			{
				if(y<=b[i])break;
				else me+=y;
			}
			else {
				cnt++;
				if(cnt>=minn-1)return 1;
			}
			me-=b[i];
			if(me<=0)break;
		}
	if(cnt>=minn-1&&me>0)return 1;
	else
	return 0;	
}


int main()
{
	scanf("%d%d%d%d%d",&n,&x,&y,&h1,&h2);
	int i,j;
	minn=(h2+x-1)/x;
	for(i=1;i<=n;++i)
	scanf("%d",&a[i]);
	
	int l=0,r=n+1,mid;
	while(l<r-1){
		mid=(r-l)/2+l;
		if(check(mid))r=mid;
		else l=mid;
	}
	int cnt=0;
	if(r!=n+1)printf("Win\n%d\n",r);
	else{
		sort(a+1,a+n+1);
		for(i=1;i<=n;++i)
		{
			if(h1-a[i]<=0)
			{
				if(y<=a[i])break;
				else h1+=y;
			}
			else cnt++;
			h1-=a[i];
			if(h1<=0)break;
		}
		//++cnt;
		printf("Lose\n%d\n",x*cnt);
	}
	
    return 0;
}

