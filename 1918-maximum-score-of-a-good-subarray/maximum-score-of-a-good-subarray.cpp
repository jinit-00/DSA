class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k;
        int j = k;
        int n = nums.size();
        long long  result = nums[k];
        int small = nums[k];
        while(i>0 || j<n-1)
        {
            if(i==0)
            {
                j++;
                small = min(small,nums[j]);
            }
            else if(j==n-1)
            {
                i--;
                small = min(small,nums[i]);
            }
            else if(nums[i-1]>nums[j+1])
            {
                i--;
                small = min(small,nums[i]);
            }
            else
            {
                j++;
                small = min(small,nums[j]);
            }
            result = max(result,(long long)small * (j-i+1));
        }
    return result;
    }
};