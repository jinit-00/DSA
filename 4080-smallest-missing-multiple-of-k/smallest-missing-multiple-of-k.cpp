class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int find = k;
        while(st.count(find))
        {
            find += k;
        }
    return find;
    }
};