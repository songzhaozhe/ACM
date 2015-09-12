#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

const int maxn=20010;
const int INF=199999999;

bool vis[50000];

struct Point {
    int x,y;
    Point(int x = 0,int y = 0): x(x),y(y){}
    Point(const Point &A){
        x = A.x;
        y = A.y;
    }
};

struct sq{
    Point p[4];
    sq(){};
    sq(Point a, Point b, Point c, Point d){
        p[0] = a;
        p[1] = b;
        p[2] = c;
        p[3] = d;
    }
    sq(Point a,Point b){
        p[0]=a;
        p[2]=b;
        p[1].x = b.x;
        p[1].y = a.y;
        p[3].x = a.x;
        p[3].y = b.y;
    }
    
    void read(){
        char ch;
        int x1,y1,x2,y2;
        ch = getchar();
        while(ch!='(')ch = getchar();
        scanf("%d",&x1);
        ch = getchar();
        scanf("%d",&y1);
        while(ch!='(')ch = getchar();
        scanf("%d",&x2);
        ch = getchar();
        scanf("%d",&y2);
        ch = getchar();
        ch = getchar();
        p[0] = Point(x1,y1);
        p[1] = Point(x2,y1);
        p[2] = Point(x2,y2);
        p[3] = Point(x1,y2);        
    }
    void print(){
        printf("%d %d %d %d\n",p[0].x,p[0].y,p[2].x,p[2].y);
    }
    
};

vector<sq> up,down;
vector<int> loc[11][4];

int n,m;

bool overlap(sq a, sq b){
    
    if (a.p[0].x >= b.p[2].x || a.p[2].x <= b.p[0].x || a.p[0].y >= b.p[2].y || a.p[2].y <= b.p[0].y)
    return 0;    
    return 1;
}

bool ok(sq a, int st){
    sq s[4];
    Point T[4];
    T[0].x = (a.p[0].x + a.p[2].x + 1)/2;
    T[0].y = (a.p[0].y + a.p[2].y + 1)/2;
    T[1].x = (a.p[0].x + a.p[2].x)/2;
    T[1].y = (a.p[0].y + a.p[2].y + 1)/2;    
    T[2].x = (a.p[0].x + a.p[2].x)/2;
    T[2].y = (a.p[0].y + a.p[2].y)/2;
    T[3].x = (a.p[0].x + a.p[2].x + 1)/2;
    T[3].y = (a.p[0].y + a.p[2].y)/2;    
    int flag[4] = {0};
    
    s[0] = sq(a.p[0],T[0]); 
    s[2] = sq(T[2],a.p[2]);
    s[1] = sq(Point(T[1].x,a.p[1].y),Point(a.p[1].x,T[1].y));
    s[3] = sq(Point(a.p[3].x,T[3].y),Point(T[3].x,a.p[3].y));
    
//    s[0].print();
//    s[1].print();
    for (int i = 0; i < 4; ++i)
    {
    //    s[i] = sq(a.p[i],T[i]);
        for (int j = 0; j < down.size(); ++j)
        {
            if ((1<<j & st))continue;
            if (overlap(s[i],down[j])){flag[i] = 1;break;}        
        }        
    }
    int cnt = 0;
    for (int i = 0; i < 4; ++i)
    if(flag[i])++cnt;
    if (cnt<=1)return 0;
    if (cnt>=3)return 1;
    return flag[0] == flag[2];    
}

bool check(int st){
    for (int i = 0; i < up.size(); ++i)
    {
        if (!ok(up[i],st)){
            return 0;
        }
    }
    return 1;    
}

inline int lowbit(int x){
    return x & (-x);
}
int cal(int x){
    int cnt = 0;
    int xx = x;
    while(x>0){
        cnt++;
        x -= lowbit(x);
    }
    //if(cnt==3)cout<<xx<<endl;
    return cnt;
}

int ans;

bool cantake(int j, int st){
    for (int d = 0; d < 4; ++d)
    {
        int flag = 1;
        for (int i = 0; i < loc[j][d].size(); ++i)
        {
            int k = loc[j][d][i];
            if ((1<<k & st) ==0){
                flag = 0;
                break;
            }            
        }
        if (flag)return 1;        
    }
    return 0;
}


void dfs(int state){
    if(vis[state])return;
    vis[state] = 1;
    if (!check(state))return;
    ans = max(ans,cal(state));
    
    for (int j = 0; j < m; ++j)
    {
        if (1<<j & state)continue;
        if (cantake(j,state))dfs(state | (1<<j));        
    }    
}

bool is_left(sq a,sq b){
    if (a.p[0].y >= b.p[3].y||a.p[3].y <= b.p[0].y)return 0;
    else return a.p[0].x >= b.p[0].x;
}
bool is_right(sq a,sq b){
    if (a.p[0].y >= b.p[3].y||a.p[3].y <= b.p[0].y)return 0;
    else return a.p[0].x <= b.p[0].x;
}
bool is_up(sq a,sq b){
    if (a.p[0].x >= b.p[2].x || a.p[2].x <= b.p[0].x)return 0;
    else return a.p[0].y <= b.p[0].y;
}
bool is_down(sq a,sq b){
    if (a.p[0].x >= b.p[2].x || a.p[2].x <= b.p[0].x)return 0;
    else return a.p[0].y >= b.p[0].y;
}

void init(){
//    cout<<"@@"<<endl;
    for (int i = 0; i < 11; ++i)
    for (int j = 0; j < 4; ++j)
    loc[i][j].clear();
    //cout<<"##"<<endl;
    
    for (int i = 0; i < down.size(); ++i)
    for (int j = 0; j < down.size(); ++j)
    {
        if (i == j)continue;
        if (is_left(down[i],down[j])){
            loc[i][3].push_back(j);
        }
        else if (is_right(down[i],down[j])){
            loc[i][1].push_back(j);
        }
        else if (is_up(down[i],down[j])){
            loc[i][2].push_back(j);
        }
        else if (is_down(down[i],down[j])){
            loc[i][0].push_back(j);
        }        
    }    
}


int main()
{
    int cas = 1;
    while(1){
        scanf("%d",&m);
        memset(vis,0,sizeof(vis));
        if (m == 0)break;
        scanf("%d",&n);
        sq tmp;
        ans = 0;
        
        up.clear();
        down.clear();
        for (int i = 1; i <= m; ++i)
        {
            tmp.read();
            //tmp.print();
            down.push_back(tmp);
        }
        for (int i = 1; i <= n; ++i)
        {
            tmp.read();
            up.push_back(tmp);
        }
        init();
        dfs(0);    
        printf("Case %d: %d\n",cas++,ans);
        
    }    
    return 0;
}


