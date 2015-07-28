#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<algorithm> 
#include<vector>
#include<set> 
#define LL long long
using namespace std;

const int maxn=100010;
const int INF=199999999;

int n;

struct Card{
	int h,w;	
};

Card a[maxn],b[maxn];
multiset<int>s;

bool operator <(const Card a,const Card b)
{
	return a.w<b.w;
}


int main()
{
	int T,i,j,x,y,ans;
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{scanf("%d%d",&x,&y);a[i].w=x;a[i].h=y;}
		for(i=1;i<=n;++i)
		{scanf("%d%d",&x,&y);b[i].w=x;b[i].h=y;}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		j=n;
		for(i=n;i>=1;--i)
		{
			while(j>=1&&a[j].w>=b[i].w)s.insert(a[j--].h);
			multiset<int>::iterator t=s.lower_bound(b[i].h);
			if(t==s.end())continue;
			++ans;
			s.erase(t);
		}
		cout<<ans<<'\n';
		s.clear();
	} 
	
    return 0;
}

