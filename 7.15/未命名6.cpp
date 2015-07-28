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

const int maxn=200100;
const int INF=199999999;
const LL MOD1=1e9+7;
const LL MOD2=1234567777;

struct node{
	int x;
	int y;
};

node hash1[maxn],hash2[maxn],hash3[maxn];
char s[maxn],p[maxn];

int m,n;
LL mul1[maxn],mul2[maxn];

node operator -(node a,node b){
	return (node){(a.x-b.x+MOD)%MOD,(a.y-b.y+MOD)%MOD};
}
node operator *(node a, int m){
	return (node){a.x*mul1[m]%MOD1,a.y*mul2[m]%MOD2;
}

node gethash1(int x,int y)
{
	return (hash1[y]-hash1[x-1]*(y-x+1));
}


int main()
{
	scanf("%s%s",s+1,p+1);
	int n=strlen(s+1),m=strlen(p+1);
	int i;
	for(i=1;i<=n;++i)s[i+n]=s[i];
	for(i=1;i<=m;++i)p[i+m]=p[i];
	
	mul1[0]=mul2[0]=1;
	for(i=1;i<maxn;++i){
		mul1[i]=mul1[i-1]*31%MOD1;
		mul2[i]=mul2[i-1]*29%MOD2;
	}
	
	for(i=1;i<=2*n;++i)
	{
		hash1[i].x = (hash1[i-1].x*31+s[i]-'a')%MOD1;
		hash1[i].y = (hash2[i-1].y*29+s[i]-'a')%MOD2;
	}
	for(i=1;i<=2*m;++i)
	{
		hash2[i].x = hash2[i-1].x*31+p[i]-'a')%MOD1;
		hash2[i].y = hash2[i-1].y*29+p[i]-'a')%MOD2;
	}
	for(i=1;i<=2*n;++i)
	{
		hash3[i].x = hash3[i+1].x*31+s[i]-'a')%MOD1;
		hash3[i].y = hash3[i+1].y*29+s[i]-'a')%MOD2;
	}
	
	
	
    return 0;
}

