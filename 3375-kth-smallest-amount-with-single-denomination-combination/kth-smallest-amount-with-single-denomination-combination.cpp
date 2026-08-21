class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }

    ll count(ll x, vector<int>& coins) {
        int n = coins.size();
        ll ans = 0;

        // Inclusion-exclusion
        for (int mask = 1; mask < (1 << n); mask++) {
            ll L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i]);

                    // No multiple of L can be <= x
                    if (L > x)
                        break;
                }
            }

            if (L > x)
                continue;

            ll ways = x / L;

            if (bits & 1)
                ans += ways;
            else
                ans -= ways;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll lo = 1;

        // The kth amount can be at most k * smallest coin
        ll mn = *min_element(coins.begin(), coins.end());
        ll hi = mn * (ll)k;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (count(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};