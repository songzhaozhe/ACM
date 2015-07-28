#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long LL;

const int maxn=20010;
const int INF=199999999;

int m,n;
char s[20];
LL s0[maxn],s2[maxn],s1[maxn];
LL sum[maxn],sqrsum[maxn];
LL tag[maxn];


void update(int o,int L,int R)
{
	int mid=L+(R-L)/2;
	if(tag[o])
	{
		s0[o]+=tag[o]*(R-L+1);
		s1[o]+=tag[o]*(sum[R]-sum[L-1]);
		s2[o]+=tag[o]*(sqrsum[R]-sqrsum[L-1]);
		tag[o*2]+=tag[o];
		tag[o*2+1]+=tag[o];
	}
	tag[o]=0;
}

void modify(int o,int L, int R,int ll,int rr,int v)
{
	if(ll<=L&&rr>=R){
		tag[o]+=v;
		update(o,L,R);
		return;
	}
	update(o,L,R);
	int mid=L+(R-L)/2;		
	if(ll<=mid)modify(o*2,L,mid,ll,rr,v);
	if(rr>mid)modify(o*2+1,mid+1,R,ll,rr,v);
	update(o*2,L,mid);update(o*2+1,mid+1,R);
	s0[o]=s0[o*2]+s0[o*2+1];
	s1[o]=s1[o*2]+s1[o*2+1];
	s2[o]=s2[o*2]+s2[o*2+1];	
	return;
}

LL query(int o,int L,int R,int ll,int rr)
{
	update(o,L,R);
	LL ret=0;
	if(ll<=L&&rr>=R)
	{
		ret-=(rr+1)*(ll-1)*s0[o];
		ret+=(rr+ll)*s1[o];
		ret-=s2[o];
		return ret;
	}
	int mid=L+(R-L)/2;
	if(ll<=mid)ret+=query(o*2,L,mid,ll,rr);
	if(mid<rr)ret+=query(o*2+1,mid+1,R,ll,rr);
	return ret;
}


int main()
{
	int i,j,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+i;
		sqrsum[i]=sqrsum[i-1]+i*i;
	}	
	for(i=1;i<=m;++i)
	{
		scanf("%s",s);
		if(s[0]=='c'){
			scanf("%d%d%d",&x,&y,&z);
			modify(1,1,n-1,x,y-1,z);
		}
		else{
			scanf("%d%d",&x,&y);
		//	for(i=1;i<=2*n;++i)
		//	cout<<s1[i]<<' ';cout<<endl;
			LL ret=query(1,1,n-1,x,y-1);
			double ans;
			ans=1.0*ret/2.0;
			ans/=y-x;
			ans/=y-x+1;
			printf("%.9f\n",ans);
			
		}
	}
	 
	
    return 0;
}

