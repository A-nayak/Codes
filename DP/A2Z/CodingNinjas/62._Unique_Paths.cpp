// https://leetcode.com/problems/unique-paths/
// pure recursion

class Solution {
public:
    int helper(int m,int n,int i,int j){
        if(i>=m || j>=n)    //out of bound case so path is invalid return 0
        return 0;
        if(i==m-1 && j==n-1)   // we reached destination mark path as valid and count 1 valid path
        return 1;
        int right=helper(m,n,i,j+1);   // move right check if we can reach destination moving right
        int down=helper(m,n,i+1,j); // same as above but for down
        return right+down;   // total ways to reach destination moving right and down
    }
    int uniquePaths(int m, int n) {
        return helper(m,n,0,0);
    }
};


// rec + memo
class Solution {
public:
    vector<vector<int>>dp;
    int helper(int m,int n,int i,int j){
        if(i>=m || j>=n)
        return 0;
        if(i==m-1 && j==n-1)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int right=helper(m,n,i,j+1);
        int down=helper(m,n,i+1,j);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        return helper(m,n,0,0);
    }
};
