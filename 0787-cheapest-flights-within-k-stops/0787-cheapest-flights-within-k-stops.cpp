class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            graph[u].push_back({v, wt});
        }

        queue<pair<pair<int, int>, int>> q; //(node, cost), stops
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        q.push({{src, dist[src]}, -1});

        while(q.size() > 0){
            int curr = q.front().first.first;
            int d = q.front().first.second;
            int stops = q.front().second;
            q.pop();

            for(auto& p : graph[curr]){
                if(dist[p.first] > (d + p.second) && (stops + 1) <= k){
                    dist[p.first] = (d + p.second);
                    q.push({{p.first, dist[p.first]}, stops+1});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};