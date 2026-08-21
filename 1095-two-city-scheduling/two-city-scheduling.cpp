class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        long long answer = 0;
        int n = costs.size();
        n = n/2;
        for(int i=0;i<n;i++)
        {
            answer += costs[i][0];
        }
        n = 2*n;
        for(int i=n/2;i<n;i++)
        {
            answer+= costs[i][1];
        }
    return answer;
    }
};