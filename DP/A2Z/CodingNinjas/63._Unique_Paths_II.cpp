// https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    int helper(vector<vector<int>>& g,int m,int n,int i,int j){
        if(i>=m || j>=n)
        return 0;
        if(g[i][j]==1)
        return 0;
        if(i==m-1 && j==n-1)
        return 1;
        int right=helper(g,m,n,i+1,j);
        int down=helper(g,m,n,i,j+1);
        return right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        return helper(g,m,n,0,0);
    }
};

class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& g,int m,int n,int i,int j){
        if(i>=m || j>=n)
        return 0;
        if(g[i][j]==1)
        return 0;
        if(i==m-1 && j==n-1)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int right=helper(g,m,n,i+1,j);
        int down=helper(g,m,n,i,j+1);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        dp.resize(m,vector<int>(n,-1));
        return helper(g,m,n,0,0);
    }
};
