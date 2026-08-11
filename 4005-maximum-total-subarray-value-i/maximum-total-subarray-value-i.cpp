class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long greatest = *max_element(nums.begin(),nums.end());
        long long smallest = *min_element(nums.begin(),nums.end());
        return k*(greatest - smallest);
    }
};