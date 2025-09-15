class Solution {
public:
    void bfs(unordered_map<int,vector<int>>&adj,int u,vector<int>&visited,queue<int>&q){
        q.push(u);
        visited[u]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
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
        queue<int>q;
        vector<int>visited(V,false);
        for(int u=0;u<V;u++){
            if(!visited[u]){
                count++;
                bfs(adj,u,visited,q);
            }
        }
        return count;
    }
};
