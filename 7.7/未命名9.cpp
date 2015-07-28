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

const int maxn=200010;
const int INF=199999999;

string s[maxn];

void work(const string &s)
{
	int len=s.length(),i;
	string ans;
		for(i=0;i<len;++i) 
		{
			if(!((s[i]>='a'&&s[i]<='z')||s[i]==' '||s[i]=='\t'))continue;
			
			//if(s[i]>='A'&&s[i]<='Z')continue;
			if(s[i]=='d'&&s[i+1]=='d'){
				ans=ans+"p";
				++i;
				continue;
			}
			if(s[i]=='c'&&s[i+1]=='e'&&s[i+2]=='i')
			{
				ans=ans+"cei";
				i+=2;
				continue;
			}
			if(s[i]=='e'&&s[i+1]=='i')
			{
				ans=ans+"ie";
				i++;
				continue;
			}
			if(s[i]=='p'&&s[i+1]=='i'&&s[i+2]=='n'&&s[i+3]=='k')
			{
				ans=ans+"floyd";
				i+=3;
				continue;
			}
			ans+=s[i];			
			
		}
		cout<<ans<<'\n';	

} 


int main()
{
	int ter=0,rear=-1,flag=0,i;
	getline(cin,s[++rear]);	
	while(s[rear]!="EOF")
	{
		if(s[rear].substr(s[rear].length()-3,3)=="EOF")
		{
			s[rear]=s[rear].substr(0,s[rear].length()-3);
			++rear;
			break;
		}
		
		if(s[rear].length()>=80)flag=1;
		getline(cin,s[++rear]);
	}
		
	if(!flag)	//cout<<"new:"<<s<<endl;
	for(i=0;i<rear;++i)
	work(s[i]);
	else
	{
		for(i=0;i<rear;++i)
		cout<<s[i]<<'\n'; 
	}

	
    return 0;
}
