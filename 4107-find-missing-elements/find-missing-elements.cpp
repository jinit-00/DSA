class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {    
        int mi = *min_element(nums.begin(),nums.end());
        int ma = *max_element(nums.begin(),nums.end());
        vector<int> answer;
        unordered_set<int> mp(nums.begin(),nums.end());
        for(int i=mi;i<=ma;i++)
        {
            if(!mp.count(i))
            answer.push_back(i);
        }
    return answer;
    }
};