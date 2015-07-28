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

int ans[maxn];

int f[maxn][maxn];
int m1,m2;
int a1[maxn],a2[maxn];
int maxx=0;
int ma[maxn];
pair<int ,int >fa[maxn][maxn],pos; 


int main()
{
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
			fa[i][j]=make_pair(i-1,j);
			continue;
		}
		int tmpm=0,t=0;
		for(k=1;k<j;++k)
		if(a2[k]<a2[j]&&tmpm<f[i-1][k]){
			t=k;
			tmpm=f[i-1][k];
		}
		tmpm++;

		fa[i][j]=make_pair(i-1,t);
		f[i][j]=tmpm;
		if(tmpm>maxx){
			maxx=tmpm;
			pos=make_pair(i,j);
		}
	}
	
	int q[maxn],rear=-1;
	while(pos.first!=0&&pos.second!=0)
	{
	//	cout<<pos<<"####"<<endl;
		if(a1[pos.first]==a2[pos.second])
		q[++rear]=a2[pos.second];
		pos=fa[pos.first][pos.second];
	}
	
	
	cout<<maxx<<endl;
	for(i=rear;i>0;--i)
	cout<<q[i]<<' ';
	cout<<q[i]<<'\n';
	
    return 0;
}
