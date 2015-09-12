#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=2e6+10;

int W;
int a[maxn]; 

struct Node{
	int x1,x2,y1,y2;
	int x,y;
	int t;
	int v;
	int id;
	int left;
}p[200000];

int ans[200000];

inline int lowbit(int x){
	return x & (-x);
}
int query(int n){
	int ret = 0;
	while(n>0){
		ret += a[n];
		n -= lowbit(n);
	}
	return ret;
}
int add(int v,int n){
	while (n <= W){
		a[n] += v;
		n += lowbit(n);  
	}	
}

bool operator < (const Node & a, const Node &b){
	if (a.x != b.x)return a.x < b.x;
	else return a.t < b.t;
}

void CDQ(int L, int R){
	if (L==R){
		return;
	}
	int mid = (L+R)>>1;
	CDQ(L,mid);
	CDQ(mid + 1, R);

	vector<Node>v;
	for (int i = L; i <= mid; ++i)
	if (p[i].t == 1){
		v.push_back(p[i]);
	}
	for (int i = mid + 1; i <= R; ++i)
	if (p[i].t == 2){
		p[i].x = p[i].x1 - 1;
		p[i].y = p[i].y1;
		p[i].left = 1;
		v.push_back(p[i]);
		p[i].x = p[i].x2;
		p[i].y = p[i].y2;
		p[i].left = 0;
		v.push_back(p[i]);		
	}
	sort(v.begin(),v.end());
	//cout<<L<<' '<<R<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
	//	cout<<v[i].t<<endl;
		
		if (v[i].t == 1){
			add(v[i].v, v[i].y);			
		}else{
			int cur = v[i].id;
			if (p[cur].x1 == v[i].x + 1 && p[cur].y1 == v[i].y){
				ans[cur] -= query(p[cur].y2) - query(p[cur].y1 - 1);				
			}else{
				ans[cur] += query(p[cur].y2) - query(p[cur].y1 - 1);
			}			
		}		
	}
	
//	cout<<L<<' '<<R<<endl;
//	for (int i = 1; i <= 4; ++i)
//	printf("%d ",a[i]);
//	puts("");	

	return;
}


int main()
{	
	freopen("mokia.in","r",stdin);
	freopen("mokia.out","w",stdout);
	int t;
	scanf("%d%d",&t, &W);
	int i;
	for (i = 1;; ++i)
	{
		scanf("%d",&t);
		if (t==1){
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].v);
			p[i].t = 1;
			p[i].id = i;	
		}
		if (t==2){
			scanf("%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
			p[i].t = 2;
			p[i].id = i;
		}
		if (t==3){
			break;
		}		
	}
	int n = --i;
	//cout<<"###"<<n<<endl;
	CDQ(1,n);
	
	for (int i = 1; i <= n; ++i)
	if(p[i].t==2)
	printf("%d\n",ans[i]);
	
	
	return 0;
}


