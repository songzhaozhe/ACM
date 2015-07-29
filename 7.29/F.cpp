#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 40100;


int h,w;
struct Point{
	int x,y;
};

Point star[maxn],ob[maxn];
int mapp[110][110],cur[110];
int s,o,cnt;

vector<int>row[110];
vector<int>line[110];
vector<int>g[maxn];


void add(int a,int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}

int from[maxn];
bool use[maxn];

bool match(int x){
	for(int i=0;i<g[x].size();++i)
	if(!use[g[x][i]]){
		use[g[x][i]]=true;
		if(from[g[x][i]]==-1||match(from[g[x][i]])){
			from[g[x][i]]=x;
			return true;
		}
	}
	return false;
}

int hungary(){
	int tot=0;
	memset(from,-1,sizeof(from));
	for(int i=1;i<=cnt;++i){
		memset(use,0,sizeof(use));
		if(match(i))
			++tot;
	}
	return tot;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		
		cnt=0;
		for(int i=0;i<110;++i)
		{
			row[i].clear();
			line[i].clear();
		}
		for(int i=0;i<maxn;++i)
		g[i].clear();
		
		scanf("%d%d",&h,&w);
		scanf("%d",&s);
		for(int i=1;i<=s;++i)
		{
			scanf("%d%d",&star[i].x,&star[i].y);
			
		}
		scanf("%d",&o);
		for(int i=1;i<=o;++i)
		{
			scanf("%d%d",&ob[i].x,&ob[i].y);
			mapp[ob[i].x][ob[i].y]=++cnt;
			row[ob[i].x].push_back(ob[i].y);
			line[ob[i].y].push_back(ob[i].x);
		}
		for(int i=0;i<=w;++i)
		{
			mapp[0][i]=++cnt;
			line[i].push_back(0);
			sort(line[i].begin(),line[i].end());			
		}
		for(int i=0;i<=h;++i)
		{
			mapp[i][0]=++cnt;
			row[i].push_back(0);
			sort(row[i].begin(),row[i].end());
		}
		vector<int>::iterator t;
		for(int i=1;i<=s;++i)
		{
			int x,y;
			t=lower_bound(row[star[i].x].begin(),row[star[i].x].end(),star[i].y);
			--t;
			y=*t;
			t=lower_bound(line[star[i].y].begin(),line[star[i].y].end(),star[i].x);
			--t;
			x=*t;
			//cout<<x<<' '<<y<<endl;
			add(mapp[star[i].x][y],mapp[x][star[i].y]+cnt);			
		}
		
		printf("%d\n",hungary());
			
		
	}
		
		
	
	return 0;
}
