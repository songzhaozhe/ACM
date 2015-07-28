#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s1[2005],s2[2005];
int next[2005],rem[2005][60],f[2001][2001];
bool visit[2001][2001];
int main()
{
	scanf("%s%s",s1+1,s2+1);
	int len = strlen(s2+1),n = strlen(s1+1);
	next[1] = 0,next[0] = -1;
	for (int i = 2; i <= len; i++)
	{
		int p = next[i - 1];
		while(p != -1 && s2[p+1] != s2[i]) p = next[p];
		if(s2[p + 1] == s2[i])next[i] = p + 1; 	
	}
	for (int i = 0; i <= len; i++)
	{
		for (int k = i ; k != -1; k = next[k])
		if(!rem[i][s2[k+1]-'A'+1])
		{
			rem[i][s2[k+1]-'A'+1] = k+1;
			
		}
	}
	visit[0][0] = true;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= len; j++)
		if(visit[i][j])
		{
			//printf("%d %d %d\n",i,j,f[i][j]);
			if(s1[i + 1] != '?')
			{
				f[i + 1][rem[j][s1[i + 1] - 'A' + 1]] = max(f[i][j] + (j == len),f[i + 1][rem[j][s1[i + 1] - 'A' + 1]] );
				visit[i+1][rem[j][s1[i + 1] - 'A' + 1]] = true;
			}
			else
			{
				for (int k = 1; k <= 58; k++)
				{
					f[i+1][rem[j][k]] = max(f[i+1][rem[j][k]],f[i][j] + (j == len));
					visit[i+1][rem[j][k]] = true;
				}
			}
		}
	}int ans = 0;
	for (int i = 0; i <= len; i++)
	if(visit[n][i])
	{
		ans = max(f[n][i] + (i == len),ans);
	} printf("%d\n",ans);
	return  0;
}
