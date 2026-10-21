#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        // One operation: leave a fixed prefix (s[0] must be the min)
        // or a fixed suffix (s[n-1] must be the max).
        if (s[0] == mn || s[n - 1] == mx) return 1;
        // Worst case: s[0] is the unique max and s[n-1] is the unique min.
        if (count(s.begin(), s.end(), mx) == 1 && s[0] == mx &&
            count(s.begin(), s.end(), mn) == 1 && s[n - 1] == mn)
            return 3;
        return 2;
    }
};