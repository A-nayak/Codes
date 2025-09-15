class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        queue<int>q;
        vector<int>in(V,0);
        int count=0;
        for(int u=0;u<V;u++){
            for(auto v:adj[u]){
                in[v]++;
            }
        }
        for(int i=0;i<V;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        // vector<int>result;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            count++;
            // result.push_back(u);
            for(auto v:adj[u]){
                in[v]--;
                if(in[v]==0){
                    q.push(v);
                }
            }
        }
        if(count!=V){
            return true;
        }
        else
        return false;
    }
};
