class Solution {
public:
    bool checkValidString(string s) {
        int leftmin = 0;
        int leftmax = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                leftmin++;
                leftmax++;
            }
            else if(s[i]==')')
            {
                leftmin--;
                leftmax--;
            }
            else
            {
                leftmin--;
                leftmax++;
            }
            if(leftmin<0)
            leftmin = 0;
            if(leftmax<0)
            return false;
        }
        if(leftmax>=0 && leftmin == 0)
        return true;
        return false;
    }
};