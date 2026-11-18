class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n + 1);

        // u -> v with weight w
        for (auto x : times) {
            int u = x[0];
            int v = x[1];
            int w = x[2];

            adj[u].push_back({v, w});
        }

        // {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            // Try all neighbours
            for (auto x : adj[node]) {

                int nextNode = x.first;
                int weight = x.second;

                if (d + weight < dist[nextNode]) {

                    dist[nextNode] = d + weight;

                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};