#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

const int maxn=1010;

char s[maxn],p[maxn];
int next[maxn];
int f[maxn][maxn];
int q[maxn][maxn],rear[maxn];
int ans=0;
int flag[maxn][maxn]={0};

void getFail(char *P,int *f)
{
	int m=strlen(P);
	f[0]=0;f[1]=0;
	for(int i=1;i<m;++i)
	{
		int j=f[i];
		while(j&&P[i]!=P[j])j=f[j];
		f[i+1]=P[i]==P[j]?j+1:0;
	}
}

int main()
{
	cin>>s>>p;

	int n,m;
	n=strlen(s);
	m=strlen(p);
	p[m]='#';
	p[m+1]='\0';	
	getFail(p,next);
	int i,j,k;
	memset(rear,0,sizeof(rear));
	rear[0]=0;
	q[0][0]=0;
	for(i=0;i<n;++i)
	flag[i][0]=1; 
	int prej;
	
	//for(i=0;i<=m;++i)cout<<next[i]<<endl;
	for(i=0;i<n;++i)
	{
		if(s[i]!='?')
		{
			for(k=0;k<=rear[i];++k)
			{
				prej=j=q[i][k];
				while(j&&s[i]!=p[j])j=next[j];
				if(s[i]==p[j]){
				//	f[i+1][j+1]=f[i][j];
					++j;
					if(j==m){
						//if(!flag[i+1][j])
						//q[i+1][++rear[i+1]]=j,flag[i+1][j]=1;						
				
						f[i+1][j]=max(f[i+1][j],f[i][prej]+1),ans=max(ans,f[i+1][j]);
						if(!flag[i+1][j])q[i+1][++rear[i+1]]=j,flag[i+1][j]=1;
						
						
						cout<<i<<' '<<j<<endl;
					}
					else {
			//		cout<<"@@@"<<i<<endl;
						if(!flag[i+1][j])
						q[i+1][++rear[i+1]]=j,flag[i+1][j]=1;
						f[i+1][j]=max(f[i][prej],f[i+1][j]);
					//	cout<<j<<endl;
					}			
				}
				//j==0
			//	else if(!flag[i+1][0]){flag[i+1][0]=1;q[i+1][++rear[i+1]]=0;}
			f[i+1][0]=ans;
			//f[i+1][0]=max(f[i+1][0],f[i][prej]);
			}
		}
		else
		{
		//	cout<<"EE"<<i<<' '<<rear[i]<<endl;
			for(k=0;k<=rear[i];++k)
			{
				prej=j=q[i][k];
			//	cout<<"###"<<j<<endl;
				if(j==m){//cout<<"##"<<endl;
				j=next[j];}
				while(j)
				{
					if(j==m-1){
				//		cout<<j<<endl;
						if(!flag[i+1][j+1])q[i+1][++rear[i+1]]=j+1;
						flag[i+1][j+1]=1;
						f[i+1][j+1]=max(f[i][j]+1,f[i+1][j+1]);
						//cout<<f[
						ans=max(ans,f[i+1][j+1]);
						cout<<"@@@"<<i<<endl;
					}
					else{
						if(!flag[i+1][j+1])q[i+1][++rear[i+1]]=j+1;
						flag[i+1][j+1]=1;
						f[i+1][j+1]=max(f[i+1][j+1],f[i][j]);
					}
					j=next[j];
					
				}//while(j);
					if(j==m-1){
				//		cout<<j<<endl;
						if(!flag[i+1][j+1])q[i+1][++rear[i+1]]=j+1;
						flag[i+1][j+1]=1;
						f[i+1][j+1]=max(f[i][j]+1,f[i+1][j+1]);
						//cout<<f[
						ans=max(ans,f[i+1][j+1]);
					//	cout<<"@@@"<<i<<endl;
					}	
								
				else {if(!flag[i+1][j+1])q[i+1][++rear[i+1]]=j+1;
					flag[i+1][j+1]=1;
					f[i+1][j+1]=max(f[i+1][j+1],f[i][j]);
					} 
					//j=next[j];
					
				f[i+1][0]=ans; 
				//f[i+1][0]=max(f[i+1][0],f[i][prej]);
			}	
		}		
	}
	cout<<ans<<endl;
	//cout<<f[3][1]<<' '<<f[4][1]<<endl;
		
	
}

/*
cba?bacfsdfcabc????
cbac
3

*/ 
