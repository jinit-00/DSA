class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left ;
        vector<int> right;
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == pivot)
                count++;
            else if(nums[i] < pivot)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        for(int i=0;i<count;i++)
            left.push_back(pivot);
        left.insert(left.end(), right.begin(), right.end());
    return left;
    }
};