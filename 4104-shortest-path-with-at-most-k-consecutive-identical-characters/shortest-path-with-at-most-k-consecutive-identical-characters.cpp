class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        if (k == 0) return -1;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        // State: node, consecutive identical characters
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt]) continue;

            if (u == n - 1) return cost;

            for (auto [v, w] : adj[u]) {
                int newCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (newCnt > k) continue;

                if (cost + w < dist[v][newCnt]) {
                    dist[v][newCnt] = cost + w;
                    pq.push({cost + w, v, newCnt});
                }
            }
        }

        return -1;
    }
};