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


typedef pair<int,int> pii;

typedef long long LL;


const int maxn = 500;

int v[maxn];
struct Edgelist{
	int next[maxn],first[maxn],u[maxn],v[maxn];
	int rear;
	void init(){
		rear = -1;
		memset(first,-1,sizeof(first));
	}
	void add(int from, int to){
		next[++rear] = first[from];
		first[from] = rear;
		u[rear] = from;
		v[rear] = to;
		
		next[++rear] = first[to];
		first[to] = rear;
		u[rear] = to;
		v[rear] = from;		
	}
	
}e; 
typedef pair<int,pii> piii;
pair<int,pii> q[2000000];
pair<int,LL> f[8300][13][13];//权值，个数 
int mp[30][30];
int n,m;

void work(){
	if (n==1){
		printf("%d %d\n",v[0],1);
		return;
		
	}
	
	
	
	memset(f,0,sizeof(f));
	int rear = -1,a,b,c,front = 0;
	for (int j = 0; j <= e.rear; ++j)
	{
	//	cout<<j<<' '<<e.u[j]<<' '<<e.v[j]<<endl;
		piii tmp;
		a = tmp.first = (1<<e.v[j])|(1<<e.u[j]);
		b = tmp.second.first = e.u[j];
		c = tmp.second.second = e.v[j];
		f[a][b][c] = make_pair(v[e.u[j]] + v[e.v[j]] + v[e.u[j]] * v[e.v[j]], 1);
		
		q[++rear] =  tmp;		
	}
	while (front <= rear){
	//	cout<<front<<endl;
		piii st = q[front++];
		int last = st.second.second;
		int plast = st.second.first;
		for (int j = e.first[last]; j != -1; j = e.next[j])
		{
		//	cout<<j<<endl;
			if ( ((1<<e.v[j]) & st.first) > 0)continue;
			piii nst;
			a = nst.first = (1<<e.v[j]) | st.first;
			b = nst.second.first = last;
			c = nst.second.second = e.v[j];
			int nv = 0;
			nv = f[st.first][plast][last].first;
			nv += v[e.v[j]];
			nv += v[last] * v[e.v[j]];
			if(mp[plast][e.v[j]]) nv += v[last]*v[e.v[j]]*v[plast];
			if (nv == f[a][b][c].first){
				f[a][b][c].second += f[st.first][st.second.first][st.second.second].second;
			}
			else if (nv > f[a][b][c].first){
				if(f[a][b][c].first==0)q[++rear] = nst;	
				f[a][b][c].first = nv;
				f[a][b][c].second = f[st.first][st.second.first][st.second.second].second;
			//	q[++rear] = nst;
			}
			
		}		
	}
	LL ans1 = 0,ans2;
	a = (1<<n)-1;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	{
	
		if(f[a][i][j].first>ans1){
			ans1 = f[a][i][j].first;
			ans2 = f[a][i][j].second;
		}
		else if (f[a][i][j].first==ans1){
			ans2 += f[a][i][j].second;
		}
		
	}
	if(ans1==0){
		ans2 = 0;
	}
	
	if(n>1)ans2/=2;
	
	cout<<ans1<<' '<<ans2<<endl;
	
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		e.init();
		memset(mp,0,sizeof(mp));
		scanf("%d%d",&n,&m);
		for (int i = 0; i < n; ++i)
		scanf("%d",&v[i]);
		int x,y;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d",&x,&y);
			x--;
			y--;
			mp[x][y] = mp[y][x] = 1;
		//	cout<<"add"<<x<<' '<<y<<endl;
			e.add(x,y);
		}
		work();
		
	}
	
	
	return 0;
}


