//https://leetcode.com/problems/is-graph-bipartite/submissions/1773486132/
class Solution {
public:
    bool dfs(vector<vector<int>>& adj,int u,int currcolor,vector<int>&color){
        color[u]=currcolor;
        for(auto v:adj[u]){
            if(color[v]==currcolor){
                return false;
            }
            if(color[v]==-1){
                color[v]=1-currcolor;
                if(!dfs(adj,v,1-currcolor,color)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>color(V,-1);
        int flag=true;
        for(int i=0;i<V;i++){
            if(color[i]==-1){
            flag=dfs(adj,i,0,color);
            if(flag==false)
            break;
            }
        }
        return flag;
    }
};
