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

const int maxn=510;
const int INF=199999999;

int ans[maxn]={0};

int f[maxn][maxn]={0};
int m1,m2;
int a1[maxn],a2[maxn];
int maxx=0,pos=0;
int ma[maxn]={0};
int fa[maxn]={0};

int main()
{
	memset(fa,-1,sizeof(fa));
	cin>>m1;
	int i,j,k;
	for(i=1;i<=m1;++i)
	scanf("%d",&a1[i]);
	cin>>m2;
	for(i=1;i<=m2;++i)
	scanf("%d",&a2[i]);	
	
	for(i=1;i<=m1;++i)
	for(j=1;j<=m2;++j)
	{
		if(a1[i]!=a2[j]){
			f[i][j]=f[i-1][j];
			continue;
		}
		int tmpm=0,t=0;
		for(k=0;k<j;++k)
		if(a2[k]<a2[j]&&tmpm<f[i-1][k]){
			t=k;
			tmpm=f[i-1][k];
		}
		tmpm++;
		//if(tmpm>ma[j])
		//{
			fa[j]=t;
			f[i][j]=tmpm;
		///	ma[j]=tmpm;
			if(tmpm>maxx){
				maxx=tmpm;
				pos=j;
			}
		//}
		///else{
		//	f[i][j]=ma[j];
		//}
	}
	
	int q[maxn],rear=-1;
	while(pos!=0)
	{
	//	cout<<pos<<"####"<<endl;
		q[++rear]=a2[pos];
		pos=fa[pos];
	}
	
	
	cout<<maxx<<endl;
	i=0;
	for(i=rear;i>0;--i)
	cout<<q[i]<<' ';
	if(maxx)cout<<q[i];
	cout<<'\n';
	
    return 0;
}

