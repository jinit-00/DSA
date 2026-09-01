class Solution {
public:
    long long find(vector<int>& time,long long mid,int total)
    {
        long long answer = 0;
        for(int i=0;i<time.size();i++)
        {
        answer += mid/time[i];
        if(answer > total)
        return answer;
        }

        return answer;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ele = (long long) *min_element(time.begin(),time.end());
        long long low = (long long) ele;
        long long high = (long long) ele * totalTrips;
        while(low<=high)
        {
            long long mid = low + (high - low)/2;
            long long val = find(time,mid,totalTrips);
            cout << low << " " << high  << endl;
            cout << val;
            if(val >= totalTrips)
                high = mid-1;
            else
                low = mid+1;
        }
    return low;
    }
};