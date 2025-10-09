// https://leetcode.com/problems/triangle/description/

// pure rec

class Solution {
public:
    int helper(vector<vector<int>>& t,int n,int i,int j){
        if(i>=n)
        return INT_MAX;
        if(i==n-1)
        return t[i][j];
        int take_i=t[i][j]+helper(t,n,i+1,j);
        int take_i1=t[i][j]+helper(t,n,i+1,j+1);
        return min(take_i,take_i1);
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        return helper(t,n,0,0);
    }
};


//  rec + memo

class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& t,int n,int i,int j){
        if(i>=n)
        return INT_MAX;
        if(i==n-1)
        return t[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        int take_i=t[i][j]+helper(t,n,i+1,j);
        int take_i1=t[i][j]+helper(t,n,i+1,j+1);
        return dp[i][j]=min(take_i,take_i1);
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        dp.resize(n,vector<int>(n,-1));
        return helper(t,n,0,0);
    }
};


//  bottom up O(n^2)
// we cant go up to down means we dont have precomputation of dp[0][0]
// as problem states min cost to reach bottom we consider that state here is cost to reach from ith row to bottom so we first check for the lowest row for lowest row each element cost is there cost to reach till bottom, so for n-1th row (n-2 index wise) we use nth(n-1 index wise) row's precomputated value
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<vector<int>>dp=t;        // we just copy the t grid in dp as we have to use values of n-1th index row
        for(int i =n-2;i>=0;i--){        // this is index of rows so we move bottom to up so we start from n-2th index(n-1th row) and move till 0th index
            for(int j=0;j<=i;j++){       // this is column number so we are only interested in j values till i exp(i=3 we have 4 elements (0 based indexing))
                dp[i][j]=t[i][j]+min(dp[i+1][j],dp[i+1][j+1]);   // here you can write dp[i][j]+min(dp[i+1][j],dp[i+1][j+1]);  as we copied t in dp
            }
        }
        return dp[0][0];             // min cost to reach bottom most row from row 0
    }
};
