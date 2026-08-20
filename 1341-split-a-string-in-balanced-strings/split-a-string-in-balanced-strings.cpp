class Solution {
public:
    int balancedStringSplit(string s) {
       int left = 0;
       int answer =0;
       for(int i=0;i<s.size();i++)
       {
            if(s[i] == 'R')
            left--;
            else
            left++;
            if(left == 0)
            answer++;
       } 
    return answer;
    }
};