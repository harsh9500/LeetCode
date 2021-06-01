class Solution {
public:
    vector<vector<bool>> seen;
    int area( vector<vector<int>>& grid, int m, int n, int r, int c)
    {
        if (r < 0 || r >= m || c < 0 || c >= n || seen[r][c] || grid[r][c] == 0)
            return 0;
        seen[r][c] = true;
        return (1 + area(grid, m, n, r+1, c) + area(grid, m, n, r-1, c)
                  + area(grid, m, n, r, c-1) + area(grid, m, n, r, c+1));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        seen = vector<vector<bool>> (m,vector<bool> (n,false));
        int ans = 0;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                ans = max(ans, area(grid, m, n, r, c));
            }
        }
        return ans;
    }
};