class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>in(V,0);
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
        for(auto v:adj[i])
        in[v]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int>result;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            result.push_back(u);
            for(auto v:adj[u]){
                in[v]--;
                if(in[v]==0){
                    q.push(v);
                }
            }
        }
        return result;
    }
};
