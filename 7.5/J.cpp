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

int T,n,x,k;
char s[100],ch;
char ans[513];


int main()
{
	cin>>T;
	int i,cur,len;
	
	while(T--)
	{
		cur=0;
		scanf("%d%c",&k,&ch);
		cin.getline(s,600);
		scanf("%d",&n);
		printf("%d ",k);
//	cout<<s<<endl;
		len=strlen(s);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&x);
			cur+=x;
			if(cur<0)cur+=len;
			if(cur>=len)cur-=len;
			putchar(s[cur]); 
			
		} 
		printf("\n"); 
		
	} 
	
    return 0;
}

