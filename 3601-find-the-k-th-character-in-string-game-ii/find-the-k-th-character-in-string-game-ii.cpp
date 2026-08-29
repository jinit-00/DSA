class Solution {
public:
    char solve(long long k, int idx, vector<int>& operations) {
        if (idx < 0)
            return 'a';

        // Length before operation idx.
        // We only need to know whether it is >= k.
        long long len;

        if (idx >= 60)
            len = k;
        else
            len = 1LL << idx;

        // k is in the first half
        if (k <= len) {
            return solve(k, idx - 1, operations);
        }

        // k is in the second half
        k -= len;

        char ch = solve(k, idx - 1, operations);

        // Operation 1 shifts the second half
        if (operations[idx] == 1) {
            ch = (ch == 'z') ? 'a' : ch + 1;
        }

        return ch;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        return solve(k, operations.size() - 1, operations);
    }
};