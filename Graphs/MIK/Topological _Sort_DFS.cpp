class Solution {
  public:
    void help(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,stack<int>&st){
        visited[u]=true;
        for(auto v:adj[u]){
            if(!visited[v]){
                help(adj,v,visited,st);
            }
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>result;
        stack<int>st;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++)
        {
        if(!visited[i])
        help(adj,i,visited,st);
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
