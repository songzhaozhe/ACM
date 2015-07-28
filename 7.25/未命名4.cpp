#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=200100;
const int INF=199999999;

char a[maxn],b[maxn];

bool solve(int l1,int r1,int l2,int r2)
{
	
	if(r1-l1!=r2-l2)return 0;
	int len1=r1-l1+1;
	int len2=len1;
	if(len1%2==1){
		int j,k;
		for(j=0;j<len1;++j)
		if(a[l1+j]!=b[l2+j])return 0;
		return 1;		
	}
	else return (solve(l1,l1+len1/2-1,l2,l2+len2/2-1)&&solve(l1+len1/2,r1,l2+len2/2,r2))||(solve(l1+len1/2,r1,l2,l2+len2/2-1)&&solve(l1,l1+len1/2-1,l2+len2/2,r2));

	


	return 0;

}
int main()
{
	cin>>a>>b;
	if(solve(0,strlen(a)-1,0,strlen(b)-1))printf("YES\n");
	else printf("NO\n");
	
    return 0;
}

