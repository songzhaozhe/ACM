#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>

using namespace std;
const int maxn=1<<24;

char m[15][15];
int ans=0;

struct pos{
	int x,y;
	int num;
};
bool lcmp(pos a,pos b)
	{
		return a.y<b.y;
	}
bool rcmp(pos a,pos b)
	{
		return a.y>b.y;
	}
bool ucmp(pos a,pos b)
	{
		return a.x<b.x;
	}
bool dcmp(pos a,pos b)
	{
		return a.x>b.x;
	}

bool cmp (const pos &a,const pos &b)
{
	return a.num<b.num;
}

struct four{
	pos a[5];
	four(){
		for(int i=0;i<=4;++i)
		a[i].x=-1,a[i].num=i;		
	}
	void adjust()
	{
		sort(a+1,a+5,cmp);
	}

};

bool operator <(const pos &a,const pos &b)
{
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}
bool operator ==(const pos &a,const pos &b)
{
	return a.x==b.x&&a.y==b.y;
}
bool operator < ( four a, four b)
{
	if(!(a.a[1]==b.a[1]))return a.a[1]<b.a[1];
	else if(!(a.a[2]==b.a[2]))return a.a[2]<b.a[2];
	else if(!(a.a[3]==b.a[3]))return a.a[3]<b.a[3];
	else return a.a[4]<b.a[4];
	
}

bool operator ==(four a,four b)
{
	for(int i=1;i<=4;++i)
	if(a.a[i].x!=b.a[i].x||a.a[i].y!=b.a[i].y)return 0;
	return 1;
}

set<four>s;


pos a,b,c,d;
four q[maxn];


four left(four now)
{
	sort(now.a+1,now.a+5,lcmp);
	four next=now;
	int i,j,x,y;
	for(i=1;i<=4;++i)
	{
		x=now.a[i].x;
		for(j=now.a[i].y;j>=0;--j)
		{
			if(j==0||m[x][j-1]=='#'||m[x+1][j-1]=='#')
			break;
		}
		for(int jj=1;jj<i;++jj)
		{
			int nx=next.a[jj].x;
			if(abs(nx-x)<=1){
				if(j<next.a[jj].y+2)
				j=next.a[jj].y+2;
			}
		}	
		next.a[i].y=j;
	}
	next.adjust();
	return next;		
}

four right(four now)
{
	sort(now.a+1,now.a+5,rcmp);
	//cout<<"%%%%%%%%%%";now.print();
	four next=now;
	int i,j,x,y;
	for(i=1;i<=4;++i)
	{
		x=now.a[i].x;
		for(j=now.a[i].y;j<=6;++j)
		{
			if(j==6||m[x][j+2]=='#'||m[x+1][j+2]=='#')
			break;
		}
		for(int jj=1;jj<i;++jj)
		{
			int nx=next.a[jj].x;
			if(abs(nx-x)<=1){
				if(j>next.a[jj].y-2)
				j=next.a[jj].y-2;
			}
		}
		next.a[i].y=j;
	}
	//next.print();
	next.adjust();
	return next;
}

four up(four now)
{
	sort(now.a+1,now.a+5,ucmp);
	four next=now;
	int i,j,x,y;
	for(i=1;i<=4;++i)
	{
		y=now.a[i].y;
		for(j=now.a[i].x;j>=0;--j)
		{
			if(j==0||m[j-1][y]=='#'||m[j-1][y+1]=='#')
			break;
		}
		for(int jj=1;jj<i;++jj)
		{
			int ny=next.a[jj].y;
			if(abs(ny-y)<=1){
				if(j<next.a[jj].x+2)
				j=next.a[jj].x+2;
			}
		}	
		next.a[i].x=j;		
	}
	next.adjust();
	return next;		
}

four down(four now)
{
	sort(now.a+1,now.a+5,dcmp);
	four next=now;
	int i,j,x,y;
	for(i=1;i<=4;++i)
	{
		y=now.a[i].y;
		for(j=now.a[i].x;j<=6;++j)
		{
			if(j==6||m[j+2][y]=='#'||m[j+2][y+1]=='#')
			break;
		}
		for(int jj=1;jj<i;++jj)
		{
			int ny=next.a[jj].y;
			if(abs(ny-y)<=1){
				if(j>next.a[jj].x-2)
				j=next.a[jj].x-2;
			}
		}
		next.a[i].x=j;
	}
	next.adjust();
	return next;
}

int solve()
{
	s.clear();
	ans=0;
	four now,next;
	int rear=-1,front=0;
	int i,j;
	for(i=0;i<8;++i)
	for(j=0;j<8;++j)
	{
		if(m[i][j]=='A'&&now.a[1].x==-1)now.a[1].x=i,now.a[1].y=j;
		if(m[i][j]=='B'&&now.a[2].x==-1)now.a[2].x=i,now.a[2].y=j;
		if(m[i][j]=='C'&&now.a[3].x==-1)now.a[3].x=i,now.a[3].y=j;
		if(m[i][j]=='D'&&now.a[4].x==-1)now.a[4].x=i,now.a[4].y=j;
	}
	q[++rear]=now;
	//now.print();
	while(front<=rear)
	{
		now=q[front++];	
	//	cout<<"now"<<endl;now.print();
		next=left(now);
		//next.print();
		if(s.find(next)==s.end()){
			s.insert(next);
			q[++rear]=next;
		//	cout<<"l"<<endl;
		//	next.print(); 
		}
		next=right(now);
		if(s.find(next)==s.end()){
			s.insert(next);
			q[++rear]=next;
		}
		//printf("right");next.print();
		next=down(now);
		//next.print();
		if(s.find(next)==s.end()){
			s.insert(next);
			q[++rear]=next;
		//	cout<<"q"<<endl;next.print();
		}
		next=up(now);
		if(s.find(next)==s.end()){
			s.insert(next);
			q[++rear]=next;
		}		
	}
	return rear;
}		
		
		
		
int main()
{
	int T,cas=1,i,j;
	scanf("%d",&T);
	for(;cas<=T;++cas)
	{
		for(i=0;i<8;++i)
		scanf("%s",m[i]);
		printf("Case %d: %d\n",cas,solve());
	}

}  /*

2 
....AA.. 
....AA#. 
...#.... 
.CCBB... 
.CCBB#.. 
#...##.. 
.#DD#... 
..DD.##. 

AABBCCDD 
AABBCCDD 
........ 
........ 
........ 
........ 
........ 
........
*/ 
