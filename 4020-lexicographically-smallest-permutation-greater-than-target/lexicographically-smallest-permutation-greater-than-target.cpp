class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Count available characters.
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        // Try making the first difference at position i.
        // Go from right to left so the resulting string is minimal.
        for (int i = n - 1; i >= 0; --i) {
            // Before changing position i, we need the prefix
            // target[0..i-1] to be possible.
            if (i < n) {
                // We reconstruct the count for the prefix.
                vector<int> remaining = cnt;

                bool possible = true;

                for (int j = 0; j < i; ++j) {
                    int x = target[j] - 'a';

                    if (remaining[x] == 0) {
                        possible = false;
                        break;
                    }

                    remaining[x]--;
                }

                if (!possible)
                    continue;

                // Find the smallest character > target[i].
                int x = target[i] - 'a';

                for (int c = x + 1; c < 26; ++c) {
                    if (remaining[c] > 0) {
                        string ans = target.substr(0, i);
                        ans += char('a' + c);

                        remaining[c]--;

                        // Smallest possible suffix.
                        for (int k = 0; k < 26; ++k) {
                            ans += string(remaining[k], char('a' + k));
                        }

                        return ans;
                    }
                }
            }
        }

        return "";
    }
};