#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
//#include<cmath>
#include<map>
#include<queue>
#include<vector>
#define LL long long
using namespace std;

const int maxn=1000010;
const int INF=199999999;

string s; 
LL ans=0;
int len;
int cnt[30]={0},cntl[30]={0},cntr[30]={0},ltor[30];
int q1[maxn],q2[maxn],r1=-1,r2=-1;
string left,right,tmp1,tmp2;
int t=-1,minn=INF;
char ch='#';

int main()
{
	int flag=1;
	cin>>s;
	len=s.length();
	int i,j;
	for(i=0;i<len;++i)
	++cnt[s[i]-'A'];
	
	for(i=0;i<='Z'-'A';++i)
	{
		if(cnt[i]%2==1){
			if(ch!='#'){
				flag=0;
			}
			ch=i+'A';
		}
	}
	if(len%2==0&&ch!='#')flag=0;
	if(len%2==1&&ch=='#')flag=0;
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	//ÒÆÖÐ¼ä 
	if(len%2==1){
		for(i=0;i<len;++i)
		if(s[i]==ch&&abs(i-len/2)<minn){
			t=i;
			minn=abs(i-len/2);
		}
	}
	if(t<len/2)s=s.substr(0,t)+s.substr(t+1,len/2-t)+ch+s.substr(len/2+1,len/2);
	else s=s.substr(0,len/2)+ch+s.substr(len/2,t-len/2)+s.substr(t+1,len-t-1);
	
	ans+=minn;
	//cout<<s<<endl;
	
	
	for(i=0;i<len/2;++i)
	cntl[s[i]-'A']++;
	
	for(i=0;i<=25;++i)
	{		
		cntr[i]=cnt[i]-cntl[i];
		ltor[i]=cntl[i]-cntr[i];
	}
	
	
	for(i=len/2;i>=0;--i)
	if(ltor[s[i]-'A']>0){
		left+=s[i];
		ltor[s[i]-'A']--;
		sum+=len/2-i-left.length();
	}
	else tmp1+=s[i];
	
	for(i=len/2+1;i<len;++i)
	if(ltor[s[i]-'A']<0){
		right+=s[i];
		ltor[s[i]-'A']++;
		sum+=i-len/2-right.length();
	}
	else tmp2+=s[i];
	
	reverse(left.begin(),left.end());
	reverse(tmp1.begin(),tmp1.end());
	
	if(len%2==1)
	s=tmp1+right+ch+left+tmp2;
	else s=tmp1+right+left+tmp2;
	
	sum+=left.length()*left.length+2*left.length();
	
	
	
	
	
	
	
	
    return 0;
}

