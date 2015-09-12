#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cassert>
using namespace std;

const int Mn = 2 * 100000 + 10;
const int Me = 2 * Mn + 10;
int hd[Mn],nxt[Me],to[Me],cnt;
int n, m;
int dfn[Mn],low[Mn],ecomp[Mn],vcomp[Me];
int ecompnum,vcompnum,num;
stack<int> edge,vert,path;
vector<int> comp[Me],cycle;
inline void add(int x,int y) {
    to[cnt] = y;
    nxt[cnt] = hd[x];
    hd[x] = cnt++;
}
inline void init() {
    cnt = 0;
    memset(hd, -1, sizeof hd);
}
void findcomp(int x,int p) {
    low[x] = dfn[x] = ++num;
    vert.push(x);
    int children(0);
    for(int i = hd[x]; ~i; i = nxt[i])
        if(!dfn[to[i]])
            children++;
    for(int i = hd[x]; ~i; i = nxt[i]) { 
        if(!dfn[to[i]]) {
            edge.push(i);
            findcomp(to[i], i ^ 1);
            low[x] = min(low[x], low[to[i]]);
            if((children > 1 && p == -1) || (p != -1 && dfn[x] <= low[to[i]])) {
                vcompnum++;
                int tmp;
                do {
                    tmp = edge.top();
                    edge.pop();
                    vcomp[tmp] = vcomp[1 ^ tmp] = vcompnum;
                    
                }while(tmp != i && tmp != (1 ^ i));
            }
        } 
        else if(i != p && dfn[to[i]] < dfn[x]) {
            low[x] = min(low[x],dfn[to[i]]);
            edge.push(i);   
        }
    }
    if(dfn[x] <= low[x]) {
        ecompnum++;
        int tmp;
        do {
            tmp = vert.top();
            vert.pop();
            ecomp[tmp] = ecompnum;
        } while(tmp != x);
    }
}
inline void bicomp() {
    num = ecompnum = vcompnum = 0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(ecomp, 0, sizeof ecomp);
    memset(vcomp, 0, sizeof vcomp);
    while(!edge.empty())edge.pop();
    while(!vert.empty())vert.pop();
    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            findcomp(i,-1);
        }
    }
}
int main() {
    init(); 
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; ++i) {
        int x,y;
        scanf("%d%d",&x, &y);
        add(x, y);
        add(y, x);
    }
    bicomp();
    for (int i = 1; i <= n; ++i){
    	printf("%d %d\n",i,vcomp[i]);
	}
	puts("#####");
  
    for (int i = 1; i <= n; ++i){
    	printf("%d %d\n",i,ecomp[i]);
	}  
	
	
    return 0;
} 
/*

8 9
2 1
2 5-
1 5
1 6
6 3
3 4
4 6
7 8
7 8


*/

