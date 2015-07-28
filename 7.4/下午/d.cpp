#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=3002;
const int INF=199999999;

int n,Q;
char t[6][6];
char ans[maxn][maxn];
int e[6][15]={{},{},{},{1,3,9,27,81,243,729,2187},{1,4,16,64,256,1024},{1,5,25,125,625}};
/*int exp(int n,int q)
{	
	int ans=1;
	while(q--)ans*=n;
	return ans; 	
}*/

void drawblank(int q,int x,int y)
{
	int i,j;
	int &len=e[n][q];
	for(i=0;i<len;++i)
	for(j=0;j<len;++j)
	ans[x+i][y+j]=' ';
	return;	
}

void draw(int q,int x,int y)
{
	if(q==1)
	{
		int i,j;
		for(i=0;i<n;++i)
		for(j=0;j<n;++j)
		ans[x+i][y+j]=t[i][j];
		return;	
	}	
	int &len=e[n][q-1];
	int i,j;
	for(i=0;i<n;++i)
	for(j=0;j<n;++j)
	{
		if(t[i][j]==' '){drawblank(q-1,x+i*len,y+j*len);}
		else draw(q-1,x+i*len,y+j*len);	
	} 
	return ;
	
}


int main()
{
	//cout<<exp(2,3)<<endl;
	scanf("%d",&n);
	char ch=getchar();
	int i,j,len;
	while(n!=0)
	{
		for(i=0;i<n;++i)
		for(j=0;j<=n;++j)
		t[i][j]=getchar();
		scanf("%d",&Q);
		draw(Q,0,0);
		len=e[n][Q];
		for(i=0;i<len;++i)
		{
			for(j=0;j<len;++j)
			putchar(ans[i][j]);
			putchar('\n');
			
			//printf("%c",ans[i][j]);
			//printf("\n");
		}		
		scanf("%d",&n);
		char ch=getchar();
	}
	
	
    return 0;
}

