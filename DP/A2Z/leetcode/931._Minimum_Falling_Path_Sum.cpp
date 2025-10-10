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
