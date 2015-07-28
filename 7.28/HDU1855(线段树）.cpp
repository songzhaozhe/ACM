#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=1e5*8+100;

LL sum1[maxn],sum2[maxn];

void init()
{
	int i;
	sum1[0]=sum2[0]=0;
	for(i=1;i<maxn;++i)
	{
		sum1[i]=sum1[i-1]+i;
		sum2[i]=sum2[i-1]+(LL)i*i;
	}
}

struct SegmentTree{
	LL s1[maxn],s2[maxn],s0[maxn],tag[maxn];
	
	void update(int o,int L,int R)
	{
		if(tag[o]!=0){
			int mid=L+(R-L)/2;
			s0[o]+=tag[o]*(R-L+1);
			s1[o]+=tag[o]*(sum1[R]-sum1[L-1]);
			s2[o]+=tag[o]*(sum2[R]-sum2[L-1]);
			tag[o*2]+=tag[o];
			tag[o*2+1]+=tag[o];
			tag[o]=0;			
		}		
	}
	void modify(int o,int L,int R,int ql,int qr,LL v)
	{
		if(ql<=L&&qr>=R){
			tag[o]+=v;
			update(o,L,R);
			return;		
		}
		int mid=L+(R-L)/2;
		update(o,L,R);
		if(ql<=mid)modify(o*2,L,mid,ql,qr,v);
		if(mid<qr)modify(o*2+1,mid+1,R,ql,qr,v);
		update(o*2,L,mid);
		update(o*2+1,mid+1,R);
		s0[o]=s0[o*2]+s0[o*2+1];
		s1[o]=s1[o*2]+s1[o*2+1];		
		s2[o]=s2[o*2]+s2[o*2+1];
		return;	
	}
	LL query(int o,int L,int R,int ql,int qr)
	{
		update(o,L,R);
		LL ret=0;
		if(ql<=L&&qr>=R)
		{
			ret-=(LL)(qr+1)*(LL)(ql-1)*s0[o];
			ret+=(LL)(qr+ql)*s1[o];
			ret-=s2[o];
			return ret;		
		}
		int mid=L+(R-L)/2;
		if(ql<=mid)ret+=query(o*2,L,mid,ql,qr);
		if(mid<qr)ret+=query(o*2+1,mid+1,R,ql,qr);
		return ret;	
	}	
}T; 

char oper[20];
int n,m;
double solve(int x,int y)
{
	if(x==y){return 0;}			
	LL ret=T.query(1,1,n-1,x,y-1);
	double ans;
	ans=2.0*ret;
	ans/=1.*(y-x)*(y-x+1);
	return ans;
}


int main()
{
	init(); 
	int i,j,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%s",oper);
		if(oper[0]=='c'){
			scanf("%d%d%d",&x,&y,&z);
			if(x==y)continue;
			T.modify(1,1,n-1,x,y-1,z);
		}
		else{
			scanf("%d%d",&x,&y);
			printf("%.9f\n",solve(x,y));
		}
	}
	
	return 0;
}


