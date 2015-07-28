#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include<iostream>
using namespace std;
set <string> s;
int n, a[16][16], b[16], vis[16];
string dfs(int x)
{
	int i;
	string s="b";
	vector <string> v;
	vis[x]=1;
	for (i=0; i<n; i++)
		if (vis[i]==0 && a[x][i] && b[i]) v.push_back(dfs(i));
	sort(v.begin(), v.end());
	for (i=0; i<v.size(); i++) s+=v[i];
	s+="e";
	return s;
}
int main()
{
	int T, cas, u, v, ans, i, j, found;
	string st;
	scanf("%d", &T);
	for (cas=1; cas<=T; cas++)
	{
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for (i=1; i<n; i++)
		{
			scanf("%d%d", &u, &v);
			u--;
			v--;
			a[u][v]=a[v][u]=1;
		}
		s.clear();
		ans=0;
		for (i=1; i<(1<<n); i++)
		{
			for (j=0; j<n; j++) b[j]=(i&(1<<j))>>j;
			found=0;
			//cout<<i<<endl;
			for (j=0; j<n; j++)
				if (b[j])
				{
					memset(vis, 0, sizeof(vis));
					st=dfs(j);
					if (s.find(st)==s.end())
					{
						found=1;
						s.insert(st);
						cout<<"###"<<st<<endl;
					}
				}
			ans+=found;
		}
		for(set<string>::iterator t=s.begin();t!=s.end();++t)
		cout<<*t<<endl;
		
		
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
