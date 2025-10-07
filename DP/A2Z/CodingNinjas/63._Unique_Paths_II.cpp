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

//bottom up

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));     //no of uniq path to reach last cell if 1,..2...3...m*n cell exists
        if(g[0][0]==1)                                 // if starting node contains bomb then 0 path exists we cant move
        return 0;
        dp[0][0]=1;                                    // if only one block exists we ahve total 1 uniq way to reach there
        int flag=0;
        for(int i=0;i<m;i++){                          // if only one column exsits then we can reach by just going down if no obstacles
            if(g[i][0]==1){                            // if we find bomb anywhere in the row then all the blocks after that we cant visit by just going down and there is no block to go left so 0 ways
            dp[i][0]=0;
            flag=1;
            }
            if(!flag){                                // if no bomb found till now we have 1 uniq way to reach there
                dp[i][0]=1;
            }
        }
        flag=0;                                        // reset the flag we are going to use it again 
        for(int i=0;i<n;i++){
            if(g[0][i]==1){
            dp[0][i]=0;
            flag=1;                                   // same as above
            }
            if(!flag){
                dp[0][i]=1;
            }
        }
        for(int i=1;i<m;i++){                                    
            for(int j=1;j<n;j++){
                if(g[i][j]==1){                        // if we find bomb then we cant reach to that block so 0 ways
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];    // if the block has no bomb we check how many uniq ways exist in its left and upper block we add them to get no of uniq ways to reach that block suppose its left has bomb so we dont have any way to reach till that block and we considered it before
                }
            }
        }
        return dp[m-1][n-1];        // return no of uniq ways to reach m-1th and n-1th block
    }
};
