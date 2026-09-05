class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> smallest ; 
        int n = nums.size()-1;
        int val = nums[n];
        for(int i=n;i>=0;i--)
        {
            val = min(val,nums[i]);
            smallest.push_back(val);
        }   
        reverse(smallest.begin(),smallest.end());
        int greatest = nums[0];
        for(int i=0;i<=n;i++)
        {
            greatest = max(greatest , nums[i]);
            if(greatest - smallest[i] <= k)
            return i;
        }
    return -1;
    }
};