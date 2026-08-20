class Solution {
public:
    void find(int ind,vector<int> nums,vector<vector<int>> &answer,int n)
    {
        if(ind==n)
        {
            answer.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=ind;i<n;i++)
        {
            if(st.find(nums[i])!=st.end())
            continue;

            st.insert(nums[i]);
            swap(nums[i],nums[ind]);
            find(ind+1,nums,answer,n);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer;
        int n = nums.size();
        find(0,nums,answer,n);
        return answer;
    }
};