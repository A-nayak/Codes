//https://www.geeksforgeeks.org/problems/bipartite-graph/1
class Solution {
  public:
    bool bfs(unordered_map<int,vector<int>>&adj,int u,vector<int>&color,queue<int>&q){
        color[u]=0;
        q.push(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(color[v]==color[u]){
                    return false;
                }
                else if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<int>color(V,-1);
        bool flag=true;
        for(int i=0;i<V;i++){
            if(color[i]==-1){
            flag=bfs(adj,i,color,q);
            if(flag==false)
            break;
            }
        }
        return flag;
    }
};
