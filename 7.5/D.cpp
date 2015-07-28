#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
using namespace std;

const int maxn=20010;
const int INF=199999999;

int T,n,x;
double l,r,stay,ans;

void dfs(int num,int cur,double p,int right)
{
	if(num==n||cur<=num-n){
		ans+=right*p;
		//cout<<cur<<endl;
		return;	
	}
	//if(cur<num-n)
	dfs(num+1,cur+1,p*r,max(right,cur+1));
	dfs(num+1,cur-1,p*l,right);
	dfs(num+1,cur,p*stay,right); 
	
	
}

int main()
{
	cin>>T;
	int base,rear,i,j;
	
	while(T--)
	{
		scanf("%d%d%lf%lf",&x,&n,&l,&r);
		stay=1-l-r;
		ans=0;
		dfs(0,0,1,0);
		
		printf("%d %.4lf\n",x,ans);
	} 
	
    return 0;
}

