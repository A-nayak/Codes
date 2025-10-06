// https://leetcode.com/problems/house-robber-ii/description/

//pure recursion
class Solution {
public:
    int helper(vector<int>& nums, int i, int n) {
        if (i > n)
            return 0;
        int take = nums[i] + helper(nums, i + 2, n);
        int skip = helper(nums, i + 1, n);
        return max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        return max(helper(nums, 0, n - 2), helper(nums, 1, n-1));
    }
};

// rec + memo
class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& dp, int n) {
        if (i > n)
            return 0;
            if(dp[i]!=-1)
            return dp[i];
        int take = nums[i] + helper(nums, i + 2, dp, n);
        int skip = helper(nums, i + 1, dp, n);
        return dp[i]=max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        vector<int>dp(n,-1);
        int take_0=helper(nums, 0, dp, n - 2);
        fill(dp.begin(),dp.end(),-1); //use this or create new dp array so that changes in take_0 does not affect skip_0 
        int skip_0=helper(nums, 1, dp, n - 1);
        return max(take_0,skip_0);
    }
};

// bottom up
class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& dp, int n) {
        int len=n-i+1;
        dp[0]=0;
        dp[1]=nums[i];
        for(int j=2;j<=len;j++){
            dp[j]=max(dp[j-1],nums[i+j-1]+dp[j-2]);
        }
        return dp[len];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        vector<int>dp(n+2,-1);
        int take_0=helper(nums, 0, dp, n - 2);
        fill(dp.begin(),dp.end(),-1); //use this or create new dp array so that changes in take_0 does not affect skip_0 
        int skip_0=helper(nums, 1, dp, n - 1);
        return max(take_0,skip_0);
    }
};


// space optimized O(1)
class Solution {
public:
    int helper(vector<int>& nums, int i, int n) {
        int len=n-i+1;
        int prev2=0;
        int prev1=nums[i];       //inialize it like this so that if it dont enter loop if len is 1 then also we get correct ans
        int ans=prev1;
        for(int j=2;j<=len;j++){
            ans=max(prev1,prev2+nums[j+i-1]);  // here j+i beacuse array index for nums is fix if i=1 then we have to consider adding 1 in it to get correct house numbers
            prev2=prev1;
            prev1=ans;
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        int take_0=helper(nums, 0, n - 2);
        int skip_0=helper(nums, 1,n - 1);
        return max(take_0,skip_0);
    }
};
