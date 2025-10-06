// https://leetcode.com/problems/house-robber-ii/description/

//pure recursion
class Solution {
public:
    int helper(vector<int>& nums, int i, int n) {
        if (i >= n)
            return 0;
        int take = nums[i] + helper(nums, i + 2, n);
        int skip = helper(nums, i + 1, n);
        return max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(helper(nums, 0, n - 1), helper(nums, 1, n));
    }
};

