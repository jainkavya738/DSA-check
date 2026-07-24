class Solution {
public:
    bool isCycle(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& adj){
        vis[src] = true;
        recPath[src] = true;

        for(int v: adj[src]){
            if(!vis[v]){
                if(isCycle(v, vis, recPath, adj)) return true;
            } else{
                if(recPath[v]) return true;
            }
        }

        recPath[src] = false;

        return false;
    }

    void dfs(int src, vector<bool>& vis, vector<vector<int>>& adj, stack<int>& s){
        vis[src] = true;

        for(int v : adj[src]){
            if(!vis[v]) dfs(v, vis, adj, s);
        }

        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        stack<int> s;

        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);
        }


        bool check = true;
        for(int i = 0; i < n; i++){
            if(isCycle(i, vis, recPath, adj)){
                check = false;
                break;
            }
        }

        if(!check) return {};

        vector<bool> vis1(n, false);
        for(int i = 0; i < n; i++){
            if(!vis1[i]) dfs(i, vis1, adj, s);
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }   
};