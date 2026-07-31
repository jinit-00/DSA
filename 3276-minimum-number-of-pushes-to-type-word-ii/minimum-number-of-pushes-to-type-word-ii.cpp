class Solution {
public:
    int minimumPushes(string word) {
        vector<int> nums(26,0);
        for(int i=0;i<word.size();i++)
            nums[word[i] - 'a']++;
        sort(nums.begin(),nums.end(),greater<int>());

        int answer = 0;
        int count = 0;
        int val = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            count++;
            else 
            continue;

            if(count<=8)
            val = 1;
            else if(count<=16)
            val = 2;
            else if(count<=24)
            val = 3;
            else
            val = 4;

            answer += nums[i] * val;
            cout << answer << " ";
        }
        return answer;
    }
};