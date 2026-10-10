
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> diff;
        long long sum = 0, mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            sum += d;
            mx = max(mx, d);
        }

        if (sum <= k) return 0;

        long long l = 0, r = mx;

        while (l < r) {
            long long mid = (l + r) / 2;
            long long need = 0;

            for (long long d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k)
                r = mid;
            else
                l = mid + 1;
        }

        long long ans = 0, used = 0;

        for (long long d : diff) {
            long long x = min(d, l);
            ans += x * x;
            used += d - x;
        }

        long long remaining = k - used;

        for (long long d : diff) {
            if (remaining == 0) break;
            if (d >= l && l > 0) {
                ans -= l * l - (l - 1) * (l - 1);
                remaining--;
            }
        }

        return ans;
    }
};
