class Solution {
  public:
    bool bfs(unordered_map<int,vector<int>>& adj,int u,vector<bool>&visited){
        queue<pair<int,int>>q;
        q.push({u,-1});
        visited[u]=true;
        while(!q.empty()){
            pair<int,int>val=q.front();
            q.pop();
            int source=val.first;
            int parent=val.second;
            for(auto v:adj[source]){
                if(v==parent){
                    continue;
                }
                if(!visited[v]){
                    q.push({v,source});
                    visited[v]=true;
                }
                else{
                    return true;
                }
            }
            
        }
        return false;
    }
    bool dfs(unordered_map<int,vector<int>>& adj,int u,vector<bool>&visited,int parent){
        visited[u]=true;
        for(auto v:adj[u]){
            if(v==parent){
                continue;
            }
            if(visited[v]){
                return true;
            }
            if(dfs(adj,v,visited,u)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<bool>visited(V,false);
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<V;i++){
            if(!visited[i] && bfs(adj,i,visited)){
                return true;
            }
        }
        return false;
    }
};
