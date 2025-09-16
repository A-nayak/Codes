class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<bool>&rec,stack<int>&st){
        visited[u]=true;
        rec[u]=true;
        for(auto v:adj[u]){
            if(visited[v] && rec[v]){
                return true;
            }
            if(!visited[v] && dfs(adj,v,visited,rec,st)){
                return true;
            }
        }
        rec[u]=false;
        st.push(u);
        return false;
    }
    vector<int> findOrder(int V, vector<vector<int>>& mp) {
        unordered_map<int,vector<int>>adj;
        for(auto it:mp){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int>result;
        vector<bool>visited(V,false);
        vector<bool>rec(V,false);
        stack<int>st;
        bool flag=false;
        for(int i=0;i<V;i++){
            if(!visited[i])
            flag=dfs(adj,i,visited,rec,st);
            if(flag)
            break;
        }
        while(!st.empty()){
            int x=st.top();
            result.push_back(x);
            st.pop();
        }
        if(flag==true){
            return {};
        }
        else{
            return result;
        }
    }
};
