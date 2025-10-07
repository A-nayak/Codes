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
