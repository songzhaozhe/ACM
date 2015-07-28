#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=1000010;
const int INF=199999999;

int d[maxn],f[maxn];
string s;

void getFail(const string &P,int *f){
	int m=P.length();
	f[0]=0;
	f[1]=0;
	for(int i=1;i<m;++i){
		int j=f[i];
		while(j&&P[i]!=P[j])j=f[j];
		f[i+1]=P[i]==P[j]?j+1:0;
	} 
}

int main()
{
	int n,tmp;
	cin>>n;
	int T=1;
	
	while(n!=0)
	{
		
		cin>>s;
		cout<<"Test case #"<<T++<<endl;
		s+='#';
		getFail(s,f);
		int i;
		int len=s.length();
		for(i=1;i<n;++i)
		{
			 tmp=i+1-f[i+1];
			 if(f[i+1]==tmp){
			 	d[i]=2;
			 	cout<<i+1<<' '<<'2'<<endl;
			 	continue;			 	
			 }
			 int &pd=d[f[i+1]-1];			 
			 if(pd==0){
			 	d[i]=0;
			 	continue;
			 }
			 if(f[i+1]/pd==tmp)
			 {
			 	d[i]=pd+1;
			 	cout<<i+1<<' '<<d[i]<<endl;
			 	continue;
			 }
			 
		}
		
		cout<<endl;
		cin>>n;
	}
	
    return 0;
}

