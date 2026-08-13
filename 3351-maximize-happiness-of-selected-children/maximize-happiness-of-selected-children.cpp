class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long answer = 0;
        sort(happiness.begin(),happiness.end());
        int round = 0;
        int selected = 0;
        for(int i=happiness.size()-1;i>=0;i--)
        {
            if(selected == k)
            break;
            long long val = happiness[i] - round;
            if(val<0)
            break;
            answer += val;
            selected++;
            round++;
        }
    return answer;
    }
};