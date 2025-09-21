// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int source) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>ans(V,INT_MAX);
        ans[source]=0;
        q.push({0,source});
        while(!q.empty()){
            int d=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int dist=it.second;
                if(dist+d<ans[v]){
                    ans[v]=dist+d;
                    q.push({ans[v],v});
                }
            }
        }
        return ans;
        
    }
};
