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

char a[6],b[6];


bool cmp(char *a)
{
	char t[6];
	int i;
	for(i=0;i<=3;++i)
	t[i]=a[i];
	if(strcmp(t,b)==0)return 1; 
	t[1]=a[3];t[2]=a[1];t[3]=a[2];
	if(strcmp(t,b)==0)return 1; 
	t[1]=a[2];t[2]=a[3];t[3]=a[1];	 
	if(strcmp(t,b)==0)return 1; 
	
	return 0;
	
}

bool work()
{
	char t[6];
	int i;
	for(i=0;i<=3;++i)
	t[i]=a[i];
	if(cmp(t))return 1;;
		
	t[0]=a[1];t[1]=a[3];t[2]=a[2];t[3]=a[0];	 
	if(cmp(t))return 1;
	
	t[0]=a[2];t[1]=a[1];t[2]=a[3];t[3]=a[0];	 
	if(cmp(t))return 1;	
	
	t[0]=a[3];t[1]=a[1];t[2]=a[0];t[3]=a[2];	 
	if(cmp(t))return 1;
		
	return 0;
}

int main()
{
	cin>>a>>b;
	if(work())cout<<"equal\n";
	else cout<<"different\n";
	
	
    return 0;
}

