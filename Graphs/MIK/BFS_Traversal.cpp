// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    void solve(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<int>&result){
        queue<int>q;
        q.push(u);
        visited[u]=true;
        result.push_back(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    result.push_back(v);
                    visited[v]=true;
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &mp) {
        int V=mp.size();
        vector<bool>visited(V,false);
        vector<int>result;
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(auto v=mp[u].begin();v!=mp[u].end();v++){
                adj[u].push_back(*v);
            }
        }
        solve(adj,0,visited,result);
        return result;
    }
};
