#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn=1024*10+5;
typedef long long LL;

LL tim=0;
long long f[100000];
int p[25][4];
char flag[1825][maxn];
int mapp[100000],srear=-1;
int q[1825][25];
int a[20];
int rear=-1;
inline int count(int n)
{
	int ans=0;
	while(n>0)
	{
		if(n&1)ans++;
		n>>=1;
	}
	return ans;
}

inline void mark(int f[],char fla[],int qq[])
{
	int num,i=0;
	do{
		num=(f[p[i][0]]<<2)+((f[p[i][1]]<<1)+f[p[i][1]])+(f[p[i][2]]<<1)+f[p[i][3]];
		fla[num]++;
		qq[i]=num;
		i++;
	}while(i<=23);	
}

inline LL cal(char flag[],int q[])
{
	int i,j;
	LL ans=0;
	for(i=0;i<24;++i)
	{
	ans+=flag[q[i]];
	}

	return ans;
}	

LL work(int ii)
{
	int i,j,e[20];
	int r1,r2,k;
	int f1[6],f2[6];
	LL ans=0;	
	int pos[20],rear=-1;
	for(j=0;j<16;++j)
	if(ii>>j&1)pos[++rear]=j;
	int tot=(1<<8)-1;
	for(i=0;i<=tot;++i)
	if(count(i)==4)
	{
		int tmp1=ii,tmp2=ii;
		for(j=0;j<8;++j)
		if(i>>j&1){
			tmp1-=1<<pos[j];
		}
		else tmp2-=1<<pos[j];
		ans+=cal(flag[mapp[tmp1]],q[mapp[tmp2]]);		
	}
	
	return ans;
}

void init()
{
	int i=0,j;
	int tmp[4]={0,1,2,3};
	do{
		for(j=0;j<4;++j)
		p[i][j]=tmp[j];
		i++;
	}while(next_permutation(tmp,tmp+4));
}

void work2(int i)
{
	int j,r=-1,e[20];
	mapp[i]=++srear;
	int kk=i;
	for(j=0;j<16;++j)
	{
		if(kk&1)e[++r]=a[j];
		kk>>=1;
	}
	mark(e,flag[srear],q[srear]);
}

int main()
{
	int i,j,k,r1,r2,e[20];
	init();
	int  cas(0);
	tim=100;
	while(1)
	{
		if(cas!=0){memset(flag,0,sizeof(flag));		memset(f, 0, sizeof f);}
		tim+=100;
		cas++;
		scanf("%d",&a[0]);
		srear=-1;
		if(a[0]==0)
			break;
		for(i=1;i<16;++i)
			scanf("%d",&a[i]);
			
		for(i=0;i<(1<<16);++i)
		{
			if(count(i)==4){
				work2(i);
			}
		}					
		LL ans=0,t1,t2;
		int tot = (1 << 16) - 1;
		for(i=0;i<=tot;++i)
		{
			if(count(i)==8){
				f[i] = work(i);
			}
		}
		ans = 0;

		for(i = 0; i<= (tot>>1); ++i) {
			if(count(i) == 8) {
				ans += f[i] * f[tot ^ i];
			}
		}
		printf("Case %d: %lld\n", cas, ans / 4);
	}
}

