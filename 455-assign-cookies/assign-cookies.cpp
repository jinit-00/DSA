class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int s1 = g.size();
        int s2 = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        int l = 0;
        int r = 0;
        while(l<s1 && r<s2)
        {
            if(s[r]>=g[l])
            {
                count++;
                r++;
                l++;
            }
            else if(s[r]<g[l])
            r++;
        }
    return count;
    }
};