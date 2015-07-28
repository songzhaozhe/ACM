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

const int maxn=1000010;
const int INF=199999999;

char s[maxn],ans[maxn];

void work()
{
	int i,len=strlen(s);
	ans[len-1]=s[len-1];
	int j;
	for(j=len-2;j>=1;--j)
	{
		ans[j]=s[j]-ans[j+1]+'0';
		if(ans[j]<'0'){
			ans[j]+=10;
			s[j-1]--;
		}		
	}
	if(len>1)ans[0]=s[0]-ans[1]+'0';
	if(ans[0]=='0'){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	if(ans[0]<'0')ans[0]+=10;
	ans[len]='\0';
	printf("%s\n",ans);
	return;	
}

int main()
{
	scanf("%s",&s);
	int i;
	for(i=1;;++i)
	{
		if(s[0]=='0')break;
		printf("%d. ",i);
	//	cout<<s<<endl;
		work();
		scanf("%s",&s);
	} 
	
	
    return 0;
}

