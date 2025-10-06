// https://www.naukri.com/code360/problems/frog-jump_3621012

// pure rec
#include <bits/stdc++.h> 
int helper(vector<int>&h, int i){
    if(i==(h.size())-1)
    return 0;
    int step1=abs(h[i+1]-h[i])+helper(h,i+1);
    int step2=INT_MAX;
    if(i+2<h.size())
    step2=abs(h[i+2]-h[i])+helper(h,i+2);
    return min(step1,step2);
}
int frogJump(int n, vector<int> &h)
{
    return helper(h,0);
}

// rec + memo

#include <bits/stdc++.h> 
int helper(vector<int>&h, int i,vector<int>&dp){
    if(i==(h.size())-1)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    int step1=abs(h[i+1]-h[i])+helper(h,i+1,dp);
    int step2=INT_MAX;
    if(i+2<h.size())
    step2=abs(h[i+2]-h[i])+helper(h,i+2,dp);
    return dp[i]=min(step1,step2);
}
int frogJump(int n, vector<int> &h)
{
    vector<int>dp(n,-1);
    return helper(h,0,dp);
}


// bottom up
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &h)
{
    vector<int>dp(n,-1);   // cost to reach 0,1,2....(in question terms 1,2,3,..n)
    dp[0]=0;   //cost to reach 0(in question 1) is 0 as it is already on that step
    dp[1]=abs(h[1]-h[0]);   //to reach 1(in question 2nd step)
    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-2]+abs(h[i]-h[i-2]),dp[i-1]+abs(h[i]-h[i-1]));
    }
    return dp[n-1];   // to reach last n-1 (in question nth step)
    
}

// space optimized O(1)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &h)
{
    int prev2=0;
    int prev1=abs(h[1]-h[0]);
    int ans=prev1;
    for(int i=2;i<n;i++){
        ans=min(prev2+abs(h[i-2]-h[i]),prev1+abs(h[i-1]-h[i]));
        prev2=prev1;
        prev1=ans;
    }
    return ans;
    
}
