// https://leetcode.com/problems/minimum-path-sum/description/

// pure rec

class Solution {
public:
    int helper(vector<vector<int>>& g, int m,int n,int i,int j){
        if(i>=m || j>=n){
            return 201;
        }
        if(i==m-1 && j==n-1){
            return g[i][j];
        }
        int right=g[i][j]+helper(g,m,n,i+1,j);
        int bottom=g[i][j]+helper(g,m,n,i,j+1);
        return min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        return helper(g,m,n,0,0);
    }
};

// recursion +memo
class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& g, int m,int n,int i,int j){
        if(i>=m || j>=n){
            return INT_MAX;              
        }
        if(i==m-1 && j==n-1){
            return g[i][j];
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        long long right=g[i][j]+1ll*helper(g,m,n,i+1,j);
        long long bottom=g[i][j]+1ll*helper(g,m,n,i,j+1);
        return dp[i][j]=min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        dp.resize(m,vector<int>(n,-1));
        return helper(g,m,n,0,0);
    }
};
