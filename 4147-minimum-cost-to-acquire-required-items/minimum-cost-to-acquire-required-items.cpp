class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;
        long long m = min(n1, n2);

        long long opt1 = n1 * c1 + n2 * c2;
        long long opt2 = m * cb + (n1 - m) * min(c1, cb) + (n2 - m) * min(c2, cb);
        long long opt3 = max(n1, n2) * cb;

        return min({opt1, opt2, opt3});
    }
};