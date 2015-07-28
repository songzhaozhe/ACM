#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn=50;


const int MOD = 10000;


struct hint{
	int v[80];
	int len;
	
	hint(){
		memset(v,0,sizeof(v));
		len=0;
	}
	
	void convert(char *s)
	{
		len=0;
		int i,j,tmp;
		int slen=strlen(s);
		reverse(s,s+slen);
		for(i=3;i<slen;i+=4)
		{
			int tmp=0;
			for(j=0;j<=3;++j)
			{
					tmp*=10;
					tmp+=s[i-j]-'0';
			}
			v[len++]=tmp;
			//cout<<tmp<<"####"<<endl;
		}
		tmp=0;
		if(i==slen+3)return ;
		for(j=i-slen+1;j<=3;++j)
		tmp*=10,tmp+=s[i-j]-'0';
		v[len++]=tmp;
	}
		
	
	
	hint operator /(int x)
	{
		int i;
		hint ans=*this;
		for(i=len-1;i>=1;--i)
		{
			ans.v[i-1]+=ans.v[i]%x*MOD;
			ans.v[i]/=x;
		}
		if(ans.v[ans.len-1]==0)ans.len--;
		ans.v[0]/=x;
		return ans;
	}
	
	bool operator >(const hint &b)
	{
		if(len>b.len)return 1;
		if(len<b.len)return 0;
		int i;
		for(i=len-1;i>=0;--i)
		if(v[i]>b.v[i])return 1;
		else if(v[i]<b.v[i])return 0;
		
		return 0;
	}
	
	
	hint operator +(const hint &b)const
	{
		hint ans;
		ans.len=max(len,b.len);
		int i;
		for(i=0;i<ans.len;++i)
		{
			ans.v[i]+=v[i]+b.v[i];
			ans.v[i+1]=ans.v[i]/MOD;
			ans.v[i]%=MOD;
		}
		while(ans.v[ans.len]!=0)
		{
			ans.v[ans.len+1]+=ans.v[ans.len]/MOD;
			ans.v[ans.len]%=MOD;
			ans.len++;
		}
		return ans;
	}
	hint operator *(const hint &b)const
	{
		hint ans;
		if(len==0||b.len==0)
		return ans;	
		
		ans.len=len+b.len-1;
		int i,j;
		for(i=0;i<len;++i)
		for(j=0;j<b.len;++j)
		{
			ans.v[i+j]+=v[i]*b.v[j];
			if(ans.v[i+j]>MOD)
			{
				ans.v[i+j+1]+=ans.v[i+j]/MOD;
				ans.v[i+j]%=MOD;
			}
		}
			
		
		for(i=0;i<ans.len;++i)
		{
			ans.v[i+1]+=ans.v[i]/MOD;
			ans.v[i]%=MOD;
		}
		while(ans.v[ans.len]!=0)
		{
			ans.v[ans.len+1]+=ans.v[ans.len]/MOD;
			ans.v[ans.len]%=MOD;
			ans.len++;
		}	
		return ans;
	}	
	
	hint operator *(const int x)const
	{
		int i;
		hint ans;
		ans.len=len;
		for(i=0;i<len;++i)
		{
			ans.v[i]+=v[i]*x;
			if(ans.v[i]>=MOD){
				ans.v[i+1]+=ans.v[i]/MOD;
				ans.v[i]%=MOD;
			}
			if(ans.v[ans.len]!=0)ans.len++;
		}
		return ans;
	}
		
		
	void print()
	{
		if(len==0){printf("0\n");return;}
		int i;
		printf("%d",v[len-1]);
		for(i=len-2;i>=0;--i)
		printf("%04d",v[i]);
		printf("\n");
	}
	
};

bool ok(const hint &mid,const hint &H,const hint &h,const hint &l)
{
	hint left=(mid*mid*4+mid*4)*H*h;
	hint right=H*H+l*l;
	return left>right;
}

int T;
//hint H,I,h;

	
int main()
{
	cin>>T;
	hint one,INF,right,mid;
	one.len=1;
	one.v[0]=1;
	INF.len=26;
	int i;
	for(i=0;i<26;++i)
	INF.v[i]=9999;
	
	char s1[110],s2[110],s3[110];
	while(T--)
	{
		hint H,l,h;
		scanf("%s%s%s",s1,s2,s3);
		H.convert(s1);
		//H.print();
		l.convert(s2);
		h.convert(s3);
		hint left;
		right=INF;
		while(right>left)
		{
			mid=(left+right)/2;
			if(ok(mid,H,h,l))right=mid;
			else left=mid+one;
		}
		left.print();
	}
}
