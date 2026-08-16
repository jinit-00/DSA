class Solution {
public:
    int strStr(string haystack, string needle) {
        int a = needle.size();

        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                if (haystack.substr(i, a) == needle)
                    return i;
            }
        }

        return -1;
    }
};