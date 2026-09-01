class Solution {
public:
    int maxDistinct(string s) {
        int arr[26] = {0};
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            if(arr[s[i] - 'a'] == 0)
            {
                count++;
                arr[s[i] - 'a'] ++;
            }
        }
    return count;
    }
};