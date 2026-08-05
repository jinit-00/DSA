class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        // Find all suspicious methods
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(k);
        vis[k] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        // Check if any outside node invokes a suspicious node
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!vis[u] && vis[v]) {
                // Cannot remove suspicious group
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};