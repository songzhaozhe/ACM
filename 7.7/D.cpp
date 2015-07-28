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

int work()
{
	//cout<<s<<endl;
	int flag=0;
	string ans;
		int i,len=s.length();
		if(len>=80){return 0;}
		s=s+"#####";
		for(i=0;i<len;++i) 
		{
			if(!((s[i]>='a'&&s[i]<='z')||s[i]==' ')){flag=1;continue;}
			
			//if(s[i]>='A'&&s[i]<='Z')continue;
			if(s[i]=='d'&&s[i+1]=='d'){
				flag=1;
				ans=ans+"p";
				++i;
				continue;
			}
			if(s[i]=='c'&&s[i+1]=='e'&&s[i+2]=='i')
			{
			//	flag=1;
				ans=ans+"cei";
				i+=2;
				continue;
			}
			if(s[i]=='e'&&s[i+1]=='i')
			{
				flag=1;
				ans=ans+"ie";
				i++;
				continue;
			}
			if(s[i]=='p'&&s[i+1]=='i'&&s[i+2]=='n'&&s[i+3]=='k')
			{
				flag=1;
				ans=ans+"floyd";
				i+=3;
				continue;
			}
			ans+=s[i];			
			
		}
		s=ans;
		return flag;
	
	
}


int main()
{
	getline(cin,s);
	while(s!="EOF")
	{
		while(work());
		if(s!="")
		cout<<s<<endl;
		getline(cin,s);
	}
	
	
    return 0;
}
/*


unfloyded is an  letter word onest
vv is ok dd is ok p is not
i received mail from        liechtenstien
   aping means to imitate
EOF
unfloyded is an  letter word onest
vv is ok dd is ok p is not
i received mail from        liechtenstien
   aping means to imitate


*/
