// https://leetcode.com/problems/minimum-falling-path-sum/

// pure recursion
class Solution {
public:
    int helper(vector<vector<int>>& m,int n,int i,int j){
        if(i>=n || j>=n || j<0)
        return INT_MAX;
        if(i==n-1)
        return m[i][j];
        long long down=m[i][j]+1ll*helper(m,n,i+1,j);
        long long diag1=m[i][j]+1ll*helper(m,n,i+1,j-1);
        long long diag2=m[i][j]+1ll*helper(m,n,i+1,j+1);
        return min(down,min(diag1,diag2));
    }
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        int mini=INT_MAX;
        for(int j=0;j<n;j++)
        {
            mini=min(helper(m,n,0,j),mini);
        }
        return mini;
    }
};

// rec + memo
class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& m,int n,int i,int j){
        if(i>=n || j>=n || j<0)
        return INT_MAX;
        if(i==n-1)
        return m[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        long long down=m[i][j]+1ll*helper(m,n,i+1,j);
        long long diag1=m[i][j]+1ll*helper(m,n,i+1,j-1);
        long long diag2=m[i][j]+1ll*helper(m,n,i+1,j+1);
        return dp[i][j]=min(down,min(diag1,diag2));
    }
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        dp.resize(n,vector<int>(n,-1));
        int mini=INT_MAX;
        for(int j=0;j<n;j++)
        {
            mini=min(helper(m,n,0,j),mini);
        }
        return mini;
    }
};

// bottom up O(n^2) space
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        vector<vector<int>>dp(n,vector<int>(n+2,INT_MAX));
        for(int j=0;j<n;j++){
            dp[n-1][j+1]=m[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=n;j++){
                dp[i][j]=m[i][j-1]+min(dp[i+1][j],min(dp[i+1][j-1],dp[i+1][j+1]));
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<=n+1;j++){           // or run from 1 to n as 0 and n+1 are not real element
            mini=min(dp[0][j],mini);
        }
        return mini;
    }
};

//bottom up O(n) space
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        vector<int>prev_row(n+2,INT_MAX);          //we need two arrays why?
        vector<int>curr_row(n+2,INT_MAX);
        for(int j=1;j<=n;j++){
            prev_row[j]=m[n-1][j-1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=n;j++){
                curr_row[j]=m[i][j-1]+min(prev_row[j],min(prev_row[j-1],prev_row[j+1]));
            }                              //because here suppose if we use only one so in j=1 value we update prev_row[j] and when j=2 so j-1=1's value is altered not same as original val so we use two arrays 
            prev_row=curr_row;
        }
        int mini=INT_MAX;
        for(int j=1;j<=n;j++){
            mini=min(prev_row[j],mini);
        }
        return mini;
    }
};
