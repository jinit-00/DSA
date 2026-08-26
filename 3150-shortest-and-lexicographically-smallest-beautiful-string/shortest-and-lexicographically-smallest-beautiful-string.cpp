class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            if (ones == k) {
                // Remove leading zeros to make this window shortest.
                while (s[left] == '0')
                    left++;

                string cur = s.substr(left, right - left + 1);

                if (ans.empty() ||
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans)) {
                    ans = cur;
                }

                // Move past the first 1 so the next window
                // can contain another group of k ones.
                if (s[left] == '1') {
                    left++;
                    ones--;
                }
            }
        }

        return ans;
    }
};