//https://leetcode.com/problems/number-of-provinces/description/
class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int u,vector<int>&visited){
        visited[u]=true;
        for(auto v:adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mp) {
        int V=mp.size();
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(mp[u][v]==1){
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        int count=0;
        vector<int>visited(V,false);
        for(int u=0;u<V;u++){
            if(!visited[u]){
                count++;
                dfs(adj,u,visited);
            }
        }
        return count;
    }
};
