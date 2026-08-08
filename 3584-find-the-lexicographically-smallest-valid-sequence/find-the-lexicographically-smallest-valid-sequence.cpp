class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> suf(n + 1, 0);

        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
                suf[i]++;
            }
        }

        vector<int> ans;
        bool used = false;
        int i = 0;

        for (int k = 0; k < m; k++) {
            while (i < n) {

                if (word1[i] == word2[k]) {
                    ans.push_back(i);
                    i++;
                    break;
                }

                if (!used && suf[i + 1] >= m - k - 1) {
                    used = true;
                    ans.push_back(i);
                    i++;
                    break;
                }

                i++;
            }
        }

        if ((int)ans.size() != m) return {};
        return ans;
    }
};