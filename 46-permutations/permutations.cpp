class Solution {
public:
    void find(int ind,vector<int> nums,vector<vector<int>> &answer,int n)
    {
        if(ind == n)
        {
            answer.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            swap(nums[i],nums[ind]);
            find(ind+1,nums,answer,n);
            swap(nums[i],nums[ind]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> answer;
        int n = nums.size();
        find(0,nums,answer,n);
        return answer;
    }
};