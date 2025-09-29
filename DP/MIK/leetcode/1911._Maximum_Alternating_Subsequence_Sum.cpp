// Pure recursion

class Solution {
public:
    long long helper(vector<int>& nums,int i,bool flag){
        if(i==nums.size())
        return 0;
        long long skip=helper(nums,i+1,flag);
        int val=nums[i];
        if(flag!=true){
            val=-1*val;
        }
        long long take=val+helper(nums,i+1,!flag);
        return max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        return helper(nums,0,true);
    }
};


// using memoization

class Solution {
public:
    long long helper(vector<int>& nums,int i,int flag,vector<vector<long long>>&arr){
        if(i==nums.size())
        return 0;
        if(arr[i][flag]!=-1)
        return arr[i][flag];
        long long skip=helper(nums,i+1,flag,arr);
        int val=nums[i];
        if(flag!=true){
            val=-1*val;
        }
        long long take=val+helper(nums,i+1,!flag,arr);
        return arr[i][flag]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>arr(n,vector<long long>(2,-1));
        return helper(nums,0,1,arr);
    }
};
