class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = potions.size();
        int last = potions[n-1];
        vector<int> answer;
        for(int i=0;i<spells.size();i++)
        {
            int val = spells[i];
            long long required = ceil((1.0 * success )/ val);

            if(last < required)
            {
                answer.push_back(0);
                continue;
            }

            int index = lower_bound(begin(potions),end(potions),required) - begin(potions);
            answer.push_back(n-index);
        }
    return answer;
    }
};