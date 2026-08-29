class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;
    int result = 0;
    int non = 0; 
    void solve(vector<vector<int>>& grid, int row, int col,int count)
    {
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col] == -1)
            return;
        if(grid[row][col] == 2)
        {
            if(count == non)
            result ++;
            return;
        }
        grid[row][col] = -1;
        for(vector<int> &d : dir)
        {
            int new_i = row + d[0];
            int new_j = col + d[1];
            solve(grid, new_i,new_j,count+1);
        }
        grid[row][col] = 0;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {

        m = grid[0].size();
        n = grid.size();
        int count = 0;
        int start_i = 0;
        int start_j = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)  
            {
                if(grid[i][j] == 0)
                non++;
                
                if(grid[i][j] == 1)
                {
                    start_i = i;
                    start_j = j;
                }
            }
        }
    non++;
    solve(grid,start_i,start_j,count);
    return result;
    }
};