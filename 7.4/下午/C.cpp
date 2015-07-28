#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=20010;
const int INF=199999999;

string s; 

bool ok(const string &s,int f,int l)
{
	int i;
	int len=l-f+1;
	for(i=0;i<len/2;++i)
	if(s[f+i]!=s[l-i])return 0;
	return 1;
	
	
}

int main()
{
	cin>>s;
	int i=s.length();
	int len=i;
	int flag=0;
	for(;i>0;--i)
	{
		if(flag)break;
		int j;
		for(j=0;j<len-i+1;++j)
		if(ok(s,j,j+i-1)){
			cout<<s.substr(j,i)<<endl;
			flag=1;
			break;
		}
	} 
	
	
    return 0;
}

