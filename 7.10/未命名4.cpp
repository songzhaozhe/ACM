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

struct pii{
	int first,second;
};
bool operator <(pii a,pii b)
{
	return b.second<a.second;
}

int main()
{
	priority_queue<pii >q;
	q.push((pii){1,4});
	q.push((pii){2,3});
	cout<<q.top().second<<endl;
	
    return 0;
}

