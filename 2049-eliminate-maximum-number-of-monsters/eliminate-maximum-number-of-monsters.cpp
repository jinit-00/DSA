class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int time = 1;
        int count = 1;
        for(int i=0;i<dist.size();i++)
            dist[i] = ceil((float)dist[i]/speed[i]);


        sort(dist.begin(),dist.end());
        for(int i=1;i<dist.size();i++)
        {
            if(dist[i]<=time)
            return count;
            time++;
            count++;
        }
    return count;
    }
};