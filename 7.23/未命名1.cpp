#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;

typedef long long LL;

const LL MOD=9393937;
const LL SEED = 731;
char s[1010][510];
LL hash[1010][510],rhash[1010][510];
LL exp[510];

LL gethash(int i,int L,int R)
{
	if(L>R)return 0;
	return ((hash[i][R]+MOD-hash[i][L-1]*exp[R-L+1]%MOD)%MOD+MOD)%MOD;
}
LL getrhash(int i,int L,int R)
{
	if(L>R)return 0;
	return ((rhash[i][L]+MOD-rhash[i][R+1]*exp[R-L+1]%MOD)%MOD+MOD)%MOD;
}

int solve()
{
	int n,ans=0;
	memset(hash,0,sizeof(hash));
	memset(rhash,0,sizeof(rhash));
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;++i)
	scanf("%s",s[i]+1);
	int len1,len2,cut1,cut2;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=strlen(s[i]+1);++j)
		{
			hash[i][j]=hash[i][j-1]*SEED+s[i][j] - 'a' + 3;
			hash[i][j]%=MOD;
		}
		for(j=strlen(s[i]+1);j>=1;--j)
		{
			rhash[i][j]=rhash[i][j+1]*SEED+s[i][j] - 'a' + 3;
			rhash[i][j]%=MOD;
		}
	}
//cout<<"####"<<endl;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		if(i==j)continue;
		len1=strlen(s[i]+1);
		len2=strlen(s[j]+1);
		LL t1=(hash[i][len1]*exp[len2]+hash[j][len2])%MOD;
		LL t2=(rhash[j][1]*exp[len1]+rhash[i][1])%MOD;
		
		
	//	LL t1=(gethash(i,1,len1)*exp[len2]+gethash(j,1,len2))%MOD;
	//	LL t2=(getrhash(j,1,len2)*exp[len1]+getrhash(i,1,len1))%MOD;
		if(t1==t2)++ans;
//cout<<len1<<endl;
/*
		if(len1>len2)
		{
			cut1=(len1+len2)/2;
			if((len1+len2)%2==1)cut2=cut1+2;
			else cut2=cut1+1;
			LL t1=gethash(i,1,cut1);
//cout<<len1-cut2+1<<endl;
			LL t2=(getrhash(j,1,len2)*exp[len1-cut2+1]%MOD+getrhash(i,cut2,len1))%MOD;//
			if(t1==t2)++ans;
		}
		else if(len1<len2)
		{
			cut1=(len1+len2)/2;
			if((len1+len2)%2==1)cut2=cut1+2;
			else cut2=cut1+1;
			LL t1=(gethash(i,1,len1)*exp[cut1-len1]%MOD+gethash(j,1,cut1-len1))%MOD;
			LL t2=getrhash(j,cut2-len1,len2);
			if(t1==t2)++ans;
		}
		else
		{
			LL t1=gethash(i,1,len1);
			LL t2=getrhash(j,1,len2);
			if(t1==t2)++ans;
		}*/
		
	}
	return ans;
}
	
	
	
	
	

int main()
{
	int T;
	exp[0]=1;
//cout<<1<<endl;
	for(int i=1;i<=509;++i)
	exp[i]=exp[i-1]*SEED%MOD;
//cout<<2<<endl;
	scanf("%d",&T);
	int cas=1;
	for(;cas<=T;++cas)
	{
//cout<<"EEE"<<endl;
		printf("Case #%d: %d\n",cas,solve());
	}	
}
/*
4 4 race car ac ecar
3 xyz abac aba
5 abc ba xab x bax
5 abc ab cba ba c 

*/
