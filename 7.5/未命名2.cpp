#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#define LL long long
#include<vector>
using namespace std;

const int maxn=20010;
const int INF=199999999;
/*
class hint{
private:
	int v[400];
	int len;
public:
	hint operator +(const hint &a)
	
	
}; */

LL gcd(LL a,LL b)
		{
			if(a<0)a*=-1;
			if(b<0)b*=-1;
			LL t;
			while(b!=0)
			{
				t=a;
				a=b;
				b=t%b;
			}
			return a;
		}

class frac{
//	friend frac operator +(const frac &a,const frac &b);
//	friend frac operator -(const frac &a,const frac &b);
//	friend frac operator *(frac a,frac b);
//	friend ostream &operator <<(ostream &os,const frac &a);		
	public:
		long long up;
		long long down;

		void adjust()
		{
			LL t=gcd(up,down);
			up/=t;
			down/=t;
		}
//	public:
		frac(int x=0,int y=1):up(x),down(y){}

		int gety()const
		{
			return down;
		}
		void operator +=(const frac &a)
		{	
			LL t=gcd(down,a.down); 
			up=up*(a.down/t)+a.up*(down/t); 
			down*=a.down/t;
			adjust();
		} 
		
	
};

frac operator +(const frac &a,const frac &b)
{
	frac tmp;
	LL t=gcd(a.down,b.down);
	tmp.down=a.down/t*b.down;
	tmp.up=a.up*(b.down/t)+b.up*(a.down/t);
	tmp.adjust();
	return tmp;	
}
frac operator -(const frac &a,const frac &b)
{
	frac tmp;
	LL t=gcd(a.down,b.down);
	tmp.down=a.down/t*b.down;
	tmp.up=a.up*(b.down/t)-b.up*(a.down/t);	//cout<<tmp<<endl;
	tmp.adjust();

	return tmp;		
}

frac operator *(frac a,frac b)		
{
	frac tmp;
	LL t=gcd(a.up,b.down);
	a.up/=t;
	b.down/=t;
	t=gcd(a.down,b.up);
	a.down/=t;
	b.up/=t;
	
	tmp.down=a.down*b.down;
	tmp.up=a.up*b.up;
	tmp.adjust();
	return tmp;		
}
ostream& operator <<(ostream &os,const frac &a)
{
	if(a.down==1)
	{
		os<<a.up;
		return os;
	}
	
	os<<a.up<<'/'<<a.down;
	return os;	
}

frac f[402][405];

int p,x,m,k;

/*
frac work(int m,int k)
{
	if(f[m][k].gety()!=0)return f[m][k];
	
	
	
}*/
frac one(1,1);
void init()
{
	f[0][1]=(frac){1,1} ;
	int i,j;

	for(i=1;i<=400;++i)
	{
		frac sum;			
		for(j=2;j<=i+1;++j)
		{
			f[i][j]=(frac){i,j}*f[i-1][j-1];
			sum+=f[i][j];			
		}
		f[i][1]=one-sum;
	}
	return;
	
} 


int main()
{

	//frac aa(3,4),bb(5,6);
	//frac cc=aa-bb;
	//cout<<cc<<endl;

	init();
	//cout<<f[4][1]<<endl;
	/* 
	int i,j;
	for(i=1;i<=10;++i)
	{
		frac sum;			
		for(j=1;j<=i+1;++j)
		{
			cout<<f[i][j]<<' ';		
		}
		cout<<'\n';
	}*/ 
	
	
	cin>>p;
	while(p--)
	{
		scanf("%d%d%d",&x,&m,&k);
		printf("%d ",x);
		cout<<f[m][k]<<'\n';		
		
	}
	
    return 0;
}
