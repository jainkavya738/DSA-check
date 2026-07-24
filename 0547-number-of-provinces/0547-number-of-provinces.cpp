class Solution {
public:
    int find(int x, vector<int>& par){
        if(x == par[x]) return x;

        return par[x] = find(par[x], par);
    }

    void unionByRank(int a, int b, vector<int>& par, vector<int>& rank){
        int parA = find(a, par);
        int parB = find(b, par);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]) par[parB] = parA;
        else if(rank[parA] < rank[parB]) par[parA] = parB;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> par(n); vector<int> rank(n);

        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 0;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1) unionByRank(i, j, par, rank);
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(i == par[i]) count++;
        }

        return count;
    }
};