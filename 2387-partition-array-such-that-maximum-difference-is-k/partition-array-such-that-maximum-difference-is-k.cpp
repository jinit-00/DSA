class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {   int start = i;
            while(i<n && (long long)nums[i]-nums[start]<=k)
            {
                cout << nums[i] << " ";
                i++;
            }
            i--;
            cout << endl;
            count++;
        }
    return count;
    }
};