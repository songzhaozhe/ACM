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
const int maxe=2e5+100;
const int maxv=2e5+100;

typedef pair<int,int> pii;

int fa[maxe];

int n,m,Q;

inline int find(int x)
{
	if(fa[x]==-1)return x;
	else return fa[x] = find(fa[x]);	
}
void merge(int x, int y)
{
	int xx = find(x),yy = find(y);
	if(xx==yy)return;
	fa[xx] = yy;
	return;
}
vector<pii> col[maxv];
vector<int> e[maxv];
int s[maxv];
map<pii,int>ans;
int pos[maxv];



int main()
{
	memset(fa,-1,sizeof(fa));
	scanf("%d%d",&n,&m);
	int a,b,c;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		col[c].push_back(make_pair(a,b));
		e[a].push_back(c);
		e[b].push_back(c);
	}
	//cout<<"!!!"<<e[1].size()<<endl;
	for (int i = 1; i <= n; ++i)
	{
		sort(e[i].begin(),e[i].end());
		e[i].erase(unique(e[i].begin(),e[i].end()),e[i].end());
		s[i] = s[i-1] + e[i].size();
	}
//	cout<<"!!!"<<e[1].size()<<endl;
	for (int i = 1; i <= m; ++i)
	{
		if (col[i].size()==0)continue;
		for (int j = 0; j < col[i].size(); ++j)
		{
			int a = col[i][j].first,b = col[i][j].second;
			int A = s[a-1] + lower_bound(e[a].begin(),e[a].end(),i)-e[a].begin();
			int B = s[b-1] + lower_bound(e[b].begin(),e[b].end(),i)-e[b].begin();
			merge(A,B);	
		//	cout<<"!!!"<<A<<' '<<B<<endl;
		}		
	}
	int q;
	scanf("%d",&q);
	for (int i = 1; i <= q; ++i)
	{
		scanf("%d%d",&a,&b);
		int cnt = 0;
		if (e[a].size() > e[b].size())
		swap(a,b);
		if(ans.count(make_pair(a,b))){
			printf("%d\n",ans[make_pair(a,b)]);
			continue;
		}
		for (int j = 0; j < e[a].size(); ++j)
		{
			//cout<<"###"<<e[a][j]<<endl;
			int A = s[a-1] + j;
			if(lower_bound(e[b].begin(),e[b].end(),e[a][j])==e[b].end())continue;
			int B = s[b-1] + lower_bound(e[b].begin(),e[b].end(),e[a][j])-e[b].begin();
		//	cout<<"EEEE"<<A<<' '<<B<<endl;
			if(find(A)==find(B)){
				cnt++;
			}			
		}
		printf("%d\n",cnt);
		ans[make_pair(a,b)] = cnt;		
	}
	
	
	
	return 0;
}


