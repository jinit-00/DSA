class Solution {
public:
    int reverseDegree(string s) {
        long long answer = 0;
        int a = 1;
        for(int i=0;i<s.size();i++)
        {   
            int val = 26 - (s[i] - 'a');
            answer += (a * val);
            a += 1;
        }
    return answer;
    }
};