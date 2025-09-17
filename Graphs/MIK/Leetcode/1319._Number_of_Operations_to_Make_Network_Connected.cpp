// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
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
    int makeConnected(int n, vector<vector<int>>& mp) {
        int e=mp.size();
        if(e<n-1){
            return -1;
        }
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int count=n;
        for(auto it:mp){
            int u=it[0];
            int v=it[1];
            if((find(u))!=(find(v))){
                unio(u,v);
                n--;
            }
        }
        return n-1;
    }
};
