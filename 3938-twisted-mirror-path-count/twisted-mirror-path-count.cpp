class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> right(m + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> down(m + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long r, d, s;
                if (i == 0 && j == 0) {
                    r = d = 0;
                    s = 1;
                } else {
                    r = right[i][j];
                    d = down[i][j];
                    s = (r + d) % MOD;
                }

                if (grid[i][j] == 0) {
                    if (i == m - 1 && j == n - 1) return s % MOD;
                    if (j + 1 < n) right[i][j + 1] = (right[i][j + 1] + s) % MOD;
                    if (i + 1 < m) down[i + 1][j] = (down[i + 1][j] + s) % MOD;
                } else {
                    // entered moving right -> pushed down
                    if (i + 1 < m) down[i + 1][j] = (down[i + 1][j] + r) % MOD;
                    // entered moving down -> pushed right
                    if (j + 1 < n) right[i][j + 1] = (right[i][j + 1] + d) % MOD;
                }
            }
        }
        return 0;
    }
};