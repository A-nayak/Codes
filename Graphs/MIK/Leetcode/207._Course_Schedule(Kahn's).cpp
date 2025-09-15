class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& mp) {
        unordered_map<int,vector<int>>adj;
        for(auto it:mp){
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
        }
        vector<int>in(V,0);
        vector<int>result;
        queue<int>q;
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
        if(result.size()==V){
            return true;
        }
        else{
            return false;
        }
    }
};
