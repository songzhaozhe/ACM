#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>
#define LL long long
using namespace std;

const int maxn=20010;
const int INF=199999999;
const double pi=3.14159265359;

multiset<int> s;
struct interval{
	int r,a1,a2;
}I[maxn];

bool cmp(interval a,interval b)
{
	return a.a1<b.a1;
}

bool operator <(interval a,interval b)
{
	return a.a2>b.a2;
}


int stack[maxn],rear=-1;


priority_queue<interval>Q;
double ans;



int main()
{
	int T,n,cur=0,i;
	cin>>T;
	multiset<int>::iterator t;
	while(T--)
	{
		ans=0;
		while(!Q.empty())Q.pop();
		s.clear();
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		scanf("%d%d%d",&I[i].r,&I[i].a1,&I[i].a2);
		sort(I+1,I+n+1,cmp);
		
		cur=I[1].r;
		int pre=I[1].a1;
	//	cout<<I[1].r<<endl;
		s.insert(I[1].r);
		Q.push(I[1]);
		for(i=2;i<=n;++i)
		{
			//cout<<"FFFFOOORRR###"<<endl;
			int begin=I[i].a1;
			interval top=Q.top();
						
			while(!Q.empty()&&top.a2<begin){
				//cout<<"##"<<endl;
				ans+=1.0*(top.a2-pre)*pi/360*cur*cur;
				//cout<<"@@@"<<endl;
				pre=top.a2;
							//	cout<<"@@@"<<endl;
				Q.pop();
			//	cout<<top.r<<endl;
							//	cout<<*s.find(top.r)<<"*************"<<endl;
				//t=s.find(top.r);
				s.erase(s.find(top.r));	
							//	cout<<"@@@"<<endl;	
	
				if(Q.empty())cur=0;
				else{t=s.end();
				t--;
				cur=*t;}
				if(!Q.empty())top=Q.top();
			}
			//cout<<"$$$"<<endl;
			if(Q.empty()){
				Q.push(I[i]);
				pre=I[i].a1;
				cur=I[i].r;
			//	cout<<"insert"<<endl;
			//	cout<<I[i].r<<endl; 
				s.insert(I[i].r);
			//	s.insert(20);
			//	cout<<"success"<<endl;
			}
			else{
				ans+=1.0*(begin-pre)*pi/360*cur*cur;
				Q.push(I[i]);
				pre=begin;
				s.insert(I[i].r);
				t=s.end();
				t--;
				cur=*t;
			}
		}
	//	cout<<"@@@"<<endl;
		while(!Q.empty()){
			interval top=Q.top();
			ans+=1.0*(top.a2-pre)*pi/360*cur*cur;
			pre=top.a2;
			Q.pop();
			t=s.find(top.r);
			s.erase(t);			
			t=s.end();
			if(!Q.empty()){t--;
			cur=*t;}
		}
		printf("%.6f\n",ans);				
	}
				
		
		
		
	
	
    return 0;
}

