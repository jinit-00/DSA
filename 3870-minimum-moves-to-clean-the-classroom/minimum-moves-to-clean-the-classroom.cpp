class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int, int>> litter;

        // Number each litter cell.
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    id[r][c] = litter.size();
                    litter.push_back({r, c});
                }
            }
        }

        int k = litter.size();

        // No litter to collect.
        if (k == 0) return 0;

        int fullMask = (1 << k) - 1;

        // dist[r][c][energy][mask] would be huge, so encode
        // the complete state into one integer and use an unordered_set.
        //
        // For each (r,c,mask), store the maximum energy reached there.
        // If we've already reached the same (r,c,mask) with >= current
        // energy, the current state is dominated and can be skipped.
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        struct State {
            int r, c, e, mask;
        };

        queue<State> q;

        best[sr][sc][0] = energy;
        q.push({sr, sc, energy, 0});

        int moves = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Cannot make a move without energy.
                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        nmask |= (1 << bit);
                    }

                    // Reset energy upon entering R.
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // Dominance:
                    // For the same position + mask, having more energy
                    // is always at least as good.
                    if (best[nr][nc][nmask] >= ne)
                        continue;

                    best[nr][nc][nmask] = ne;
                    q.push({nr, nc, ne, nmask});
                }
            }

            moves++;
        }

        return -1;
    }
};