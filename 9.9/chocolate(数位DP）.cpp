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
const int maxn=1000005;

LL f[2][2][2];

int main()
{
	int T;
	cin>>T;
	while(T--){
		int n, m;
		scanf("%d%d",&n,&m);
		--n;
		--m;
		memset(f,0,sizeof(f));
		int now = 0;
		int nxt = 1;
		f[now][0][0] = 1;
		memset(f[nxt],0,sizeof(f[nxt]));
		for (int i = 0; i < 32; ++i)
		{
			nxt = now ^ 1;
			memset(f[nxt],0,sizeof(f[nxt]));
			for (int x = 0; x < 2; ++x)
				for (int y = 0; y < 2; ++y)
				{
					if (!f[now][x][y])continue;
					for (int up = 0; up < 2; ++up)
						for (int left = 0; left < 2; ++left)
						{
							int nx=0, ny=0, right, down;
							int tmp = 1 << i;
							right = (tmp & n)? 1 : 0;
							down = (tmp & m)? 1 : 0;
							right -= left + x;
							if (right < 0){
								right += 2;
								nx = 1;
							}
							down -= up + y;
							if (down < 0){
								down += 2;
								ny = 1;
							}
							if ((up ^ down ^ left ^ right) == 0)
							f[nxt][nx][ny] += f[now][x][y];							
						}					
				}			
			now ^= 1;
		}
		cout<<f[now][0][0]<<endl;		
	}	
	return 0;
}


