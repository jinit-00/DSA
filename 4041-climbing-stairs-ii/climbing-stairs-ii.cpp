class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const long long INF = LLONG_MAX / 2;
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 3; k++) {
                int i = j - k;
                if (i < 0) break;
                dp[j] = min(dp[j], dp[i] + costs[j - 1] + (long long)k * k);
            }
        }
        return (int)dp[n];
    }
};