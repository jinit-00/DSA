class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int store = 1;
        int sum = 0;
        int max1 = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]+1)
            break;
            store = i+1;
        }
        for(int i=0;i<store;i++)
            sum += nums[i];
        
        unordered_set<int> seen(nums.begin(), nums.end());
        while(seen.count(sum))
            sum++;
        return sum;
    }
};