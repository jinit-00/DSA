class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // Sort logs by time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // Sort queries with their original indices
        int m = queries.size();
        vector<pair<int, int>> qs(m);
        for (int i = 0; i < m; i++) {
            qs[i] = {queries[i], i};
        }
        sort(qs.begin(), qs.end());

        vector<int> res(m);
        vector<int> cnt(n + 1, 0);
        int active = 0;
        int left = 0, right = 0;
        int sz = logs.size();

        for (auto& [q, idx] : qs) {
            // Add logs with time <= q
            while (right < sz && logs[right][1] <= q) {
                if (cnt[logs[right][0]]++ == 0) active++;
                right++;
            }
            // Remove logs with time < q - x
            while (left < right && logs[left][1] < q - x) {
                if (--cnt[logs[left][0]] == 0) active--;
                left++;
            }
            res[idx] = n - active;
        }

        return res;
    }
};