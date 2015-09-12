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
#include<queue>
#include<sstream>
using namespace std;

typedef long long LL;

const LL MOD=1000000007;
const int maxn=41000;
const double eps = 1e-9;
const double INF = 1000000007;

int a[110];
int deg[110];

int dcmp (double x){
	return x < -eps ? -1 : x > eps;
}

struct Edgelist{
	int u[maxn], v[maxn], next[maxn], first[110];
	double flow[maxn];
	int rear;
	void init(){
		rear = -1;
		memset(first,-1,sizeof(first));
	}
	void add(int from, int to, double f){
		next[++rear] = first[from];
		first[from] = rear;
		u[rear] = from;
		v[rear] = to;
		flow[rear] = f;	
	}
}e;

int n, m;
int cur[110];

void build(double g){
	e.init();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
		if (a[i] < a[j]){
			e.add(i,j,1);
			e.add(j,i,1);
		}
	for (int i = 1; i <= n; ++i)
	{
		e.add(0,i,m);
		e.add(i,0,0);
		e.add(i,n+1,m + 2 * g - deg[i]);
		e.add(n+1,i,0);
	}	
}
bool vis[110];
int d[110];
bool BFS(int s, int t) {
	memset(vis,0,sizeof(vis));
	queue<int>Q;
	Q.push(s);
	d[s] = 0;
	vis[s] = 1;
	while (!Q.empty()){
		int x = Q.front();
		Q.pop();
		for (int j = e.first[x]; j != -1; j = e.next[j]){
			if (!vis[e.v[j]] && dcmp(e.flow[j]) == 1){
				vis[e.v[j]] = 1;
				d[e.v[j]] = d[x] + 1;
				Q.push(e.v[j]);
			}
		}
	}
	return vis[t];
}

double DFS(int x, double a, int s, int t){
	if (x == t || dcmp(a) == 0) return a;
	double flow = 0, f;
	for (int &j = cur[x]; j != -1; j = e.next[j]){
		int y = e.v[j];
		if (d[x] + 1 == d[y] && dcmp( f = DFS(y, min(a, e.flow[j]), s, t)) > 0){
			e.flow[j] -= f;
			e.flow[j^1] += f;
			flow += f;
			a -= f;
			if (dcmp(a) == 0)break;			
		}
	}
	return flow;
}

double Maxflow(int s, int t){
	double flow = 0;
	while (BFS(s, t)){
		//cout<<flow<<endl;
		for (int i = 0; i <= n + 1; ++i)
		cur[i] = e.first[i];
		flow += DFS(s,INF,s,t);
	}
	return flow;
}

bool check(double mid){
	build(mid);
	double flow = Maxflow(0,n+1);
	if ((1. * m * n - flow)/2 > eps ) return 1;
	else return 0;
}


int main()
{
	int T;
	cin>>T;
	for (int cas = 1; cas <= T; ++cas)
	{
		e.init();
		m = n = 0;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
		memset(deg,0,sizeof(deg));
		for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
		if (a[i] > a[j])
		{
			deg[i]++;
			deg[j]++;
			m++;
		}
		double ans;
		if (m == 0)ans = 0;
		else{
			double left = 1./n;
			double right = 1. * m;
			while (fabs(right - left) > eps){
				double mid = (right + left) / 2;
				if (check(mid)){
					left = mid;					
				}
				else{
					right = mid;
				}				
			}
			ans = left;			
		}		
		printf("Case #%d: %.10lf\n",cas,ans);
	} 
	
	
	return 0;
}


