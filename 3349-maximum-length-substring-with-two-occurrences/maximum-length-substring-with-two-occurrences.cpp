class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int i = 0;
        int j = 1;
        int answer = 0;
        int n = s.size();
        mp[s[0]]++;
        while(i<n && j<n)
        {
            mp[s[j]]++;
            while(mp[s[j]]>2)
            {
                mp[s[i]]--;
                i++;
            }
            answer = max(answer,j-i+1);
            j++;
        }
    return answer;
    }
};