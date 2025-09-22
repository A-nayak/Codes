// pure recursion
class Solution {
public:
    int helper(vector<int>& nums,int i){
        if(i>=nums.size())
        return 0;
        int steal=nums[i]+helper(nums,i+2);
        int skip=helper(nums,i+1);
        return max(skip,steal);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        if(nums.size()==2)
        return max(nums[0],nums[1]);
        return helper(nums,0);
    }
};



//recursion + memo
class Solution {
public:
    int helper(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size())
        return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int steal=nums[i]+helper(nums,i+2,dp);
        
        int skip=helper(nums,i+1,dp);
        return dp[i]=max(skip,steal);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        if(nums.size()==2)
        return max(nums[0],nums[1]);
        vector<int>dp(nums.size()+2,-1);
        return helper(nums,0,dp);
    }
};




// bottom-up O(n) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=nums[1-1];
        for(int i=2;i<=n;i++){
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];
    }
};

// Bottom up O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
        return nums[n-1];
        int a=0;
        int b=nums[0];
        int ans=0;
        for(int i=2;i<=n;i++){
            ans=max(nums[i-1]+a,b);
            a=b;
            b=ans;
        }
        return ans;
    }
};
