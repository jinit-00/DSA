class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallest = INT_MAX;
        int even = 0;
        int odd = 0;
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]%2 == 0)
            even++;
            else
            odd++;
            smallest = min(smallest , nums1[i]);
        }
        if(even == 0 || odd == 0)
        return true;

        if(smallest %2 != 0)
        return true;
    return false;
    }
};