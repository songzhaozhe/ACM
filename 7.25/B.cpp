#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=200010;
const int INF=199999999;

multiset<int>s;
int a[maxn];
LL ans;
int n,k;
int rear=-1;

int main()
{
	int T,i;
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&n,&k);
		s.clear();
		rear=0;
		ans=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			s.insert(a[i]);
			int A=*s.begin();
			int B=*(--s.end());
			while(B-A>=k){
				s.erase(s.find(a[++rear]));
				A=*s.begin();
				B=*(--s.end());
			}
			ans+=i-rear;
		}
		cout<<ans<<endl;
	}
			
		
		
	
	
    return 0;
}

