#include <iostream>  
 #include <stdio.h>  
 #include <string.h>  
 #include <stdlib.h>  
 using namespace std; 
  
 #define Maxn 25  
 #define LL long long  
 LL dp[Maxn][Maxn]; 
 LL ans[Maxn]; 
  
  
 void init() 
 { 
     memset(dp,0,sizeof(dp)); 
     memset(ans,0,sizeof(ans)); 
     dp[1][1] = 1; 
     ans[1] = 1; 
     for(int i=2;i<=20;i++) 
     { 
         for(int k=2;k<=i;k++) 
         { 
             dp[i][k] = dp[i-1][i+1-k] + dp[i][k-1]; 
             ans[i] += dp[i][k]; 
         } 
         ans[i] *=2; 
         //printf("%lld\n",ans[i]);  
     } 
 } 
 int main() 
 { 

     init(); 
     int p; 
     int m,n; 
     scanf("%d",&p); 
     while(p--) 
     { 
         scanf(" %d %d",&m,&n); 
         printf("%d %lld\n",m,ans[n]); 
     } 
     return 0; 
 } 
