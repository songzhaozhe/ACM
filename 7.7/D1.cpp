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

const int maxn=20010;
const int INF=199999999;

string s;

int main()
{
	getline(cin,s);
	while(1)
	{
		string ans;
		s=s+"#####";
		int len=s.length(),i;
		for(i=0;i<len;++i) 
		{
			if(s[i]=='E'&&s[i+1]=='O'&&s[i+2]=='F')
			{
				cout<<ans<<'\n';
				return 0;
			}
			
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
		cout<<ans<<endl;
		//cout<<s.length();
		//cout<<s.substr(s.length()-3,3)<<endl;
		//if(s.substr(s.length()-2,3)=="EOF")cout<<"###"<<endl;
		//if(ter)break;
		getline(cin,s);
	}
	
	
    return 0;
}
