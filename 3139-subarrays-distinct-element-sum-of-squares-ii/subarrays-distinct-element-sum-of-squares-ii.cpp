class Solution {
    static const long long MOD = 1e9 + 7;
    vector<long long> sum, sq, lazy;
    int n;

    void apply(int node, int len, long long v) {
        sq[node] = (sq[node] + 2 * v % MOD * sum[node] % MOD + v * v % MOD * len) % MOD;
        sum[node] = (sum[node] + v * len) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node]) {
            int mid = (l + r) / 2;
            apply(node * 2, mid - l + 1, lazy[node]);
            apply(node * 2 + 1, r - mid, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, v);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, v);
        update(node * 2 + 1, mid + 1, r, ql, qr, v);
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int prev = -1;
            auto it = last.find(nums[j]);
            if (it != last.end()) prev = it->second;
            update(1, 0, n - 1, prev + 1, j, 1);
            last[nums[j]] = j;
            ans = (ans + sq[1]) % MOD;
        }
        return (int)ans;
    }
};