// https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1
class Solution {
  public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unio(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(rank[parent_x]==rank[parent_y]){
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }
        else if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        }
    }
    int detectCycle(int V, vector<int> adj[]) {
        parent.resize(V,0);
        rank.resize(V,0);
        for(int u=0;u<V;u++){
            parent[u]=u;
        }
        for(int u=0;u<V;u++){
            for(auto v:adj[u]){
                if(u<v){
                    if(find(u)==find(v)){
                        return true;
                    }
                    else{
                        unio(u,v);
                    }
                }
            }
        }
        return false;
    }
};
