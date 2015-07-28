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

const int maxn=10000010;
const int INF=199999999;


int T,n,b,x,ans;
char s[maxn];

int main()
{
	cin>>T;
	int i,len;
	while(T--)
	{
		scanf("%d%d%s",&x,&b,&s);
	
		len=strlen(s);
		ans=0;
		for(i=0;i<len;++i)
		{
			ans+=s[i]-'0';
		}
		cout<<x<<' '<<ans%(b-1)<<'\n';
	}
	
    return 0;
}

