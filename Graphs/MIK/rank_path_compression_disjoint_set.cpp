// -------- FIND (with path compression) --------
int findParent(int par[], int x) {
    if (par[x] == x) return x;
    return par[x] = findParent(par, par[x]);
}

// -------- UNION (by rank) --------
void unionSet_helper(int par[], int x, int y, vector<int>& rank) {
    int px = findParent(par, x);
    int py = findParent(par, y);

    if (px == py) return; // already in same set

    if (rank[px] == rank[py]) {
        par[py] = px;
        rank[px]++;
    } else if (rank[px] > rank[py]) {
        par[py] = px;
    } else {
        par[px] = py;
    }
}

// Thin wrapper if you want a simpler call
void unionSet(int par[], vector<int>& rank, int x, int y) {
    unionSet_helper(par, x, y, rank);
}
