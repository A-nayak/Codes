class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& mp) {
        unordered_map<int,vector<int>>adj;
        queue<int>q;
        vector<int>result;
        vector<int>in(V,0);
        for(auto it:mp){
            int v=it[0];
            int u=it[1];
            adj[u].push_back(v);
        }
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
    if(result.size()!=V){
        return {};
    }
    else return result;
    }
};
