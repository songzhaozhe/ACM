#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<ctime>

#define LL long long
using namespace std;

const int maxn=20010;
const int INF=199999999;


int main()
{
	srand(time(NULL));
	int n=20;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
	cout<<rand()%2000-1000<<' ';
	cout<<endl;
		cout<<n<<endl;
	for(int i=1;i<=n;++i)
	cout<<rand()%2000-1000<<' ';
	cout<<endl;
	
    return 0;
}
/*
20
607 470 583 -169 -668 -683 -375 -126 376 280 209 -38 -19 -2 -514 883 -103 948 926 380 
20
-881 -126 -967 -732 768 -302 -356 -305 578 -762 -140 377 576 106 766 986 722 504 -708 986

*/


