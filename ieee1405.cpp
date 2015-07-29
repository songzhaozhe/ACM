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
const int maxn=1005;

int f[maxn][2100],sum[maxn];
bool ok[maxn][2100];
int a[maxn];

int main()
{
	int n;
	cin>>n;
	for( int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i-1]+a[i];
	}
	
	int maxx=0;
	f[0][0]=0;
	ok[0][0]=1;
	for(int i=1;i<=n;++i)
	for(int j=0;j<=2000;++j)
	{
		if(ok[i-1][j]){
			ok[i][j+a[i]]=1;
			f[i][j+a[i]]=max(f[i][j+a[i]],f[i-1][j]);
			if(a[i]>j){
				ok[i][a[i]-j]=1;
				f[i][a[i]-j]=max(f[i][a[i]-j],f[i-1][j]+j);
			}
			else if(a[i]<j){
				ok[i][j-a[i]]=1;
				f[i][j-a[i]]=max(f[i][j-a[i]],f[i-1][j]+a[i]);
			}
			else if(a[i]==j){
				ok[i][0]=1;
				maxx=max(maxx,f[i-1][j]+j);
				f[i][j-a[i]]=max(f[i][j-a[i]],f[i-1][j]+j);				
			}
			ok[i][j]=1;
			f[i][j]=max(f[i][j],f[i-1][j]);			
		}
	}
	if(maxx==0)cout<<"Impossible"<<endl;
	else cout<<maxx<<endl;
	
	return 0;
}


