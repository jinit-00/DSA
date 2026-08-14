class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i =0;i<n;i++)
            mp[s[i]]++;
        int answer = 0;
        int val_odd = -1;
        bool taken = false;
        for(auto it : mp)
        {
            if(it.second %2 == 0)
            answer += it.second;
            else 
            {
                if(taken == false)
                    {
                        answer += it.second;
                        taken = true;
                    }
                else
                answer += it.second-1;
            }
        }
    return answer;
    }
};