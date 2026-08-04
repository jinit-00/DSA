class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int answer = 0;
        int score = 0;
        sort(tokens.begin(),tokens.end());
        int i = 0;
        int j = tokens.size()-1;
        for(int i=0;i<=j;i++)
        {
            if(power >= tokens[i])
            {
                score++;
                power -= tokens[i];
                answer = max(answer,score);
            }
            else if(score>=1)
            {
                answer = max(answer,score);
                score--;
                power += tokens[j];
                j--;
                i--;
            }
            else
            return answer;
        }
    return answer;
    }
};