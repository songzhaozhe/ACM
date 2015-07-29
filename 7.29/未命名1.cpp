#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=1e5+100;
const int INF=199999999;

struct SegmentTree{
	int set[maxn*4],sum[maxn*4];
	
	SegmentTree(){
		memset(set,0,sizeof(set));
	}
	
	void update(int o, int L, int R)
	{
		if(set[o]!=-1)
		{
			if(L==R){
				sum[o]=set[o];
				return;
			}
			sum[o]=set[o]*(R-L+1);
			set[o*2]=set[o];
			set[o*2+1]=set[o];
		}
	}
	
	int modify(int o, int L, int R, int ql, int qr, int v)
	{
		if(ql<=L && qr>=R){
			set[o]=v;
			update(o,L,R);
			return; 
		}
		int mid=L+(R-L)/2;
		update(o,L,R);
		if(ql<=mid){
			modify(o*2, L, mid, ql, qr, v);
			
		
			
	
	
}t[30];

int n,q;
char s[maxn];

void work(int x, int y, int k)
{
	

int main()
{
	scanf("%d%d",&n,&q);
	int x,y,z;
	for(int i; i <= q; ++i)
	{
		scanf("%d%d%d", &x, &y, &z);
		work(x,y,z);
	}
	
    return 0;
}

