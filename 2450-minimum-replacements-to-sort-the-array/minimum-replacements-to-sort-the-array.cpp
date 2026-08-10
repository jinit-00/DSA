class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();
        long long a = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=a)
            {
                a = min(a,(long long)nums[i]);
            }
            else
            {
                long long val = ceil((double)nums[i] / a);
                answer = answer + val-1;
                a = nums[i]/val;
            }
        }
    return answer;
    }
};