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
        int p_x=find(x);
        int p_y=find(y);
        if(rank[p_x]==rank[p_y]){
            parent[p_y]=p_x;
            rank[p_x]++;
        }
        else if(rank[p_x]>rank[p_y]){
            parent[p_y]=p_x;
        }
        else if(rank[p_x]<rank[p_y]){
            parent[p_x]=p_y;
        }
    }
    bool equationsPossible(vector<string>& eq) {
        parent.resize(26);
        rank.resize(26);
        unordered_map<int,vector<int>>mp;
        for(auto it:eq){
            int u=it[0]-'a';
            int v=it[3]-'a';
            parent[u]=u;
            rank[u]=0;
            parent[v]=v;
            rank[v]=0;
        }
        for(auto it:eq){
            int u=it[0]-'a';
            int v=it[3]-'a';
            if(it[1]!='!'){
                if(find(u)!=find(v))
                unio(u,v);
            }
        }
        for(auto it:eq){
            int u=it[0]-'a';
            int v=it[3]-'a';
            if(it[1]=='!'){
                if(find(u)==find(v))
                return false;
            }
        }
        return true;
    }
};
