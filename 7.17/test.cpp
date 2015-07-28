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

const int maxn=20010;
const int INF=199999999;


int main()
{
		priority_queue<int,vector<int>, greater<int> >PQ;
		PQ.push(4);
		PQ.push(-1);
		PQ.push(1);
		cout<<PQ.top()<<endl;
	
    return 0;
}

