class Solution {
public:
    long long solve(vector<int>& nums, vector<int>& cost,int mid)
    {
        int n = nums.size();
        long long val = 0;
        for(int i=0;i<n;i++)
        {
            val += (long long) abs(mid-nums[i]) * cost[i];
        }
        return val;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long answer = INT_MAX;
        int left = *min_element(nums.begin(),nums.end());
        int right = *max_element(nums.begin(),nums.end());
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            long long val1 = solve(nums,cost,mid);
            long long val2 = solve(nums,cost,mid+1);
            answer = min(val1,val2);
            if(val1 < val2)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
    return answer == INT_MAX ? 0 : answer;
    }
};