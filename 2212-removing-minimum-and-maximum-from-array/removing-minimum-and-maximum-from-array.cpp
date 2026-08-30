class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int val_min = nums[0];
        int val_max = nums[0];
        int one = 0;
        int two = 0;
        for(int i=0;i<n;i++)
        {
            if(val_min>nums[i])
            {
                val_min = nums[i];
                one = i;
            }

            if(val_max<nums[i])
            {
                val_max = nums[i];
                two = i;
            }
        }
        int left = min(one,two);
        int right = max(one,two);

        int front = right + 1;
        int back = n - left;
        int both = left + 1 + (n-right);
        return min({front,back,both});
    }
};