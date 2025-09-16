#https://leetcode.com/problems/course-schedule/submissions/1772805110/
class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<bool>&rec){
        visited[u]=true;
        rec[u]=true;
        for(auto v:adj[u]){
            if(visited[v] && rec[v]){
                return true;
            }
            if(!visited[v] && dfs(adj,v,visited,rec)){
                return true;
            }
        }
        rec[u]=false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& mp) {
        unordered_map<int,vector<int>>adj;
        for(auto it:mp){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<bool>visited(V,false);
        vector<bool>rec(V,false);
        bool flag=false;
        for(int i=0;i<V;i++){
            if(!visited[i])
            flag=dfs(adj,i,visited,rec);
            if(flag)
            break;
        }
        return !flag;
    }
};
