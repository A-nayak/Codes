// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    int find(int x){
        if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
    }
    void unio(int x,int y){
        int p_x=find(x);
        int p_y=find(y);
        int rx=rank[p_x];
        int ry=rank[p_y];
        if(rx==ry){
            parent[p_y]=p_x;
            rank[p_x]++;
        }
        else if(rx>ry){
            parent[p_y]=p_x;
        }
        else{
            parent[p_x]=p_y;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
                unio(u,v);
        }
        long long count=0;
        unordered_map<int,int>cal;
        for(long long i=0;i<n;i++){
            long long x=find(i);
            cal[x]++;
        }
        long long total_part=cal.size();
        long long x=0;
        for(auto it:cal){
            x+=it.second;
            count+=((it.second)*(n-x));
        }
        return count;
    }
};
