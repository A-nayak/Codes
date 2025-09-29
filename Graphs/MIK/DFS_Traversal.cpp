// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    void helper(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<int>&result){
        if(visited[u]){
            return;
        }
        visited[u]=true;
        result.push_back(u);
        for(auto v:adj[u]){
            if(!visited[v]){
                helper(adj,v,visited,result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& mp) {
        int V=mp.size();
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(auto v=mp[u].begin();v!=mp[u].end();v++){
                adj[u].push_back(*v);
            }
        }
        vector<bool>visited(V,false);
        vector<int>result;
        helper(adj,0,visited,result);
        return result;
    }
};
