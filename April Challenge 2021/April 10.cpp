class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& cache)
    {
        if(cache[i][j]!=0)
            return cache[i][j];
        int currMax=1;
        for(int idx=0;idx<4;idx++)
        {
            int x = i + dirs[idx][0], y = j + dirs[idx][1];
            if(x<0 || y<0 || x>=m || y>=n || matrix[x][y]<=matrix[i][j])
                continue;
            currMax = max(currMax, 1 + dfs(matrix,x,y,m,n,cache));
        }
        cache[i][j] = currMax;
        return currMax;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> cache(m,vector<int>(n,0));
        int maxPath = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int len = dfs(matrix, i, j, m, n, cache);
                maxPath = max(maxPath, len);
            }
        }   
        return maxPath;
    }
};