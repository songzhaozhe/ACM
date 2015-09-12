#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 300300
using namespace std;
struct Segtree{
	Segtree *ls,*rs;
	double val;
	void* operator new (size_t)
	{
		static Segtree mempool[M<<1],*C=mempool;
		return C++;
	}
	void Build_Tree(int x,int y)
	{
		int mid=x+y>>1;
		if(x==y)
			return ;
		ls=new Segtree;
		rs=new Segtree;
		ls->Build_Tree(x,mid);
		rs->Build_Tree(mid+1,y);
	}
	void Modify(int x,int y,int l,int r,int val)
	{
		int mid=x+y>>1;
		if(x==l&&y==r)
		{
			this->val+=val;
			return ;
		}
		if(r<=mid) ls->Modify(x,mid,l,r,val);
		else if(l>mid) rs->Modify(mid+1,y,l,r,val);
		else ls->Modify(x,mid,l,mid,val),rs->Modify(mid+1,y,mid+1,r,val);
	}
	double Get_Ans(int x,int y,int pos)
	{
		int mid=x+y>>1;
		if(x==y)
			return val;
		if(pos<=mid)
			return val+ls->Get_Ans(x,mid,pos);
		else
			return val+rs->Get_Ans(mid+1,y,pos);
	}
}tree;
struct abcd{
	int pos,next;
}table[M];
struct modification{
	int l,r,p;
}modifications[M];
int head[M],tot;
int n,m,k,now;
int a[M],q[M],ans[M];
void Add(int x,int y)
{
	table[++tot].pos=y;
	table[tot].next=head[x];
	head[x]=tot;
}
void Holistic_Bisection(int x,int y,int l,int r)
{
	static int nq[M];
	int i,mid=x+y>>1;
	if(l>r) return ;
	if(x==y)
	{
		for(i=l;i<=r;i++)
			ans[q[i]]=mid;
		return ;
	}
	while(now<mid)
	{
		++now;
		if(modifications[now].l<=modifications[now].r)
			tree.Modify(1,m,modifications[now].l,modifications[now].r,modifications[now].p);
		else
			tree.Modify(1,m,1,modifications[now].r,modifications[now].p),
			tree.Modify(1,m,modifications[now].l,m,modifications[now].p);
	}
	while(now>mid)
	{
		if(modifications[now].l<=modifications[now].r)
			tree.Modify(1,m,modifications[now].l,modifications[now].r,-modifications[now].p);
		else
			tree.Modify(1,m,1,modifications[now].r,-modifications[now].p),
			tree.Modify(1,m,modifications[now].l,m,-modifications[now].p);
		--now;
	}
	int _l=l,_r=r;
	for(int j=l;j<=r;j++)
	{
		double temp=0;
		for(i=head[q[j]];i;i=table[i].next)
		{
			temp+=tree.Get_Ans(1,m,table[i].pos);
			if(temp>=1000000000)
				temp=1000000000;
		}
		if(temp>=a[q[j]])
			nq[_l++]=q[j];
		else nq[_r--]=q[j];
	}
	memcpy(q+l,nq+l,sizeof(q[0])*(r-l+1) );
	Holistic_Bisection(x,mid,l,_l-1);
	Holistic_Bisection(mid+1,y,_r+1,r);
}
int main()
{
	int i,x;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		Add(x,i);
	}
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	tree.Build_Tree(1,m);
	cin>>k;
	for(i=1;i<=k;i++)
		scanf("%d%d%d",&modifications[i].l,&modifications[i].r,&modifications[i].p);
	for(i=1;i<=n;i++)
		q[i]=i;
	Holistic_Bisection(1,k+1,1,n);
	for(i=1;i<=n;i++)
	{
		if(ans[i]<=k) printf("%d\n",ans[i]);
		else puts("NIE");
	}
	return 0;
}
