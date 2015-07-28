#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100000+11
#define LL long long
#define lc (x*2)
#define rc (x*2+1)
using namespace std;
struct Tree{
	LL sum1,sum2,sum3;
}T[MAXN*16];
int tag[MAXN*16];
LL sum[MAXN*2],sqrsum[MAXN*2];
void update(int x,int l,int r){
	if (tag[x])
	{
		T[x].sum1+=((LL)tag[x]*(r-l+1));
		T[x].sum2+=((LL)tag[x]*(sum[r]-sum[l-1]));
		T[x].sum3+=((LL)tag[x]*(sqrsum[r]-sqrsum[l-1]));
		tag[lc]+=tag[x];
		tag[rc]+=tag[x];
		tag[x]=0;
	}
}
void modify(int x,int l,int r,int ll,int rr,int d){
	update(x,l,r);
	//cout<<x<<" "<<l<<" "<<r<<endl;
	if (ll<=l&&rr>=r)
	{
		tag[x]+=d;
		update(x,l,r);
	}
	else
	{
		int mid=(l+r)>>1;
		if (ll<=mid) modify(lc,l,mid,ll,rr,d);
		if (rr>mid) modify(rc,mid+1,r,ll,rr,d);
		update(lc,l,mid);update(rc,mid+1,r);
		T[x].sum1=T[lc].sum1+T[rc].sum1;
		T[x].sum2=T[lc].sum2+T[rc].sum2;
		T[x].sum3=T[lc].sum3+T[rc].sum3;
	}
	//cout<<T[x].sum1<<endl;
}
LL query(int x,int l,int r,int ll,int rr){
	update(x,l,r);
	LL ret=0;
	//cout<<x<<" "<<l<<" "<<r<<" "<<T[x].sum1<<endl;
	if (ll<=l&&rr>=r)
	{
		ret=ret+T[x].sum1*(LL)(rr+1-(LL)ll*(rr+1));
		ret=ret+T[x].sum2*(LL)(rr+ll);
		ret=ret-T[x].sum3;
	}
	else
	{
		int mid=(l+r)>>1;
		if (ll<=mid) ret+=query(lc,l,mid,ll,rr);
		if (rr>mid) ret+=query(rc,mid+1,r,ll,rr);
		update(lc,l,mid);update(rc,mid+1,r);
		T[x].sum1=T[lc].sum1+T[rc].sum1;
		T[x].sum2=T[lc].sum2+T[rc].sum2;
		T[x].sum3=T[lc].sum3+T[rc].sum3;
	}
	return ret;
}
int n,m;
char op[200];
int main(){
	scanf("%d %d",&n,&m);getchar();
	sum[0]=sqrsum[0]=0;
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+i;
		sqrsum[i]=sqrsum[i-1]+(LL)i*i;
	}
	
	for (int i=1;i<=m;i++)
	{
		int l,r,d;
		scanf("%s",op);
		if (op[0]=='c')
		{
//			cout<<"k"<<endl;
			scanf("%d%d%d",&l,&r,&d);getchar();
			if (l==r) continue;
			modify(1,1,n-1,l,r-1,d);
		}
		if (op[0]=='e')
		{
			scanf("%d%d",&l,&r);getchar();
			if (l==r)
			{
				printf("%0.9f\n",0.0);
				continue;
			}
			LL ret=query(1,1,n-1,l,r-1);
			//cout<<ret<<endl;
			LL down=(LL)(l-r)*(LL)(l-r-1)/2;
			double ans=(ret*1.0)/(down*1.0);
			printf("%0.9f\n",ans);
		}
	}
}
