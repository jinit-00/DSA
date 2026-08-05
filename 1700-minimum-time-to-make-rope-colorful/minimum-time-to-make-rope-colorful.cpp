class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int prev = neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i] == colors[i-1])
            {   
                int curr = neededTime[i];
                time += min(prev,curr);
                prev = max(prev,curr);
            }   
            else
            {
                prev = neededTime[i];
            }
        }
    return time;
    }
};