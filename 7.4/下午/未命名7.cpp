#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=20010;
const int INF=199999999;

int e3[15]={1,3,9,27,81,243,729,2187};
int e4[15]={1,4,16,64,256,1024};
int e5[10]={1,5,25,125,625};

int e[6][15]={{},{},{},{1,3,9,27,81,243,729,2187},{1,4,16,64,256,1024},{1,5,25,125,625}};



int exp(int n,int q)
{	
	int ans=1;
	while(q--)ans*=n;
	return ans; 	
}


int main()
{
	int i;
//	for(i=0;exp(4,i)<3000;++i)
//	cout<<exp(4,i)<<','; 
	cout<<e[5][2]<<endl;
	
    return 0;
}

