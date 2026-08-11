class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum = nums[0] + nums[1];
        long long answer = -1;
        for(int i=2;i<nums.size();i++)
        {
            if(sum > nums[i])
                answer = nums[i] + sum;
            sum += nums[i];
        }
    return answer;
    }
};