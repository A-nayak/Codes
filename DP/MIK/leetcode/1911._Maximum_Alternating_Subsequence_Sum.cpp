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
