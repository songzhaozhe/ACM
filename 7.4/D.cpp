#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<queue> 
#include<vector>
#include<iomanip>
#include<algorithm> 
using namespace std;

const int maxn=100010;
const int INF=199999999;

struct Contract{
	int a,b,d;
	bool operator <(const Contract &A)const{
		return a>A.a;
	}	
};

int n;
double ans=0;
Contract c[maxn];
int dead[maxn];

bool cmp(const Contract &A,const Contract &B){
	return A.d<B.d;
}


int main()
{
	cin>>n;
	int i;
	Contract tmp;
	priority_queue<Contract>q;	
	for(i=1;i<=n;++i)
	{scanf("%d%d%d",&c[i].a,&c[i].b,&c[i].d);dead[i]=c[i].d;}
	
	sort(c+1,c+n+1,cmp);
	c[0]=(Contract){INF,0,0};
	//for(i=1;i<=n;++i)cout<<c[i].d<<endl;
	int cur=c[n].d,precur=cur;
	i=n;
	while(precur>0)
	{
		//cout<<cur<<endl;
		int flag=0;
		while(i>=1&&c[i].d==cur&&precur==cur){q.push(c[i--]);flag=1;}
		if(flag){cur=c[i].d;}
		if(!q.empty()){
			tmp=q.top();
			if(tmp.b<=precur-cur)//finish
			{
				q.pop();
				precur-=tmp.b;
			}else{//half
				q.pop();
				tmp.b-=precur-cur;
				q.push(tmp);
				precur=cur;			
			}
		}else{
			precur=cur;
		}
	}
	//while(i>=1)q.push(c[i--]);
	while(!q.empty())
	{
		tmp=q.top();
		q.pop();
		ans+=1.0*tmp.b/tmp.a;
		cout<<ans<<endl;
	}
	printf("%.2lf\n",ans);
	
	
	
    return 0;
}
/*

2
1 4 3
2 3 4

}
*/
