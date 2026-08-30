class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int len = (m*n) - 1;
        int left = 0;
        int right = len;

        while(left<=right)
        {
            int mid = left + (right - left)/2;
            int i = mid/m;
            int j = mid%m;
            if(matrix[i][j]>target)
                right = mid-1;
            else if(matrix[i][j] < target)
                left = mid+1;
            else
            return true;
        }
    return false;
    }
};