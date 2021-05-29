class Solution {
public:
    int result;
    void solve(int col, int n, vector<int> &leftRow,
              vector<int> &lowerDiagonal, vector<int> &upperDiagonal)
    {
        if(col==n)
        {
            result++;
            return;
        }
        for(int row=0; row<n; row++)
        {
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0)
            {
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, n, leftRow, lowerDiagonal, upperDiagonal);
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        result = 0;
        vector<int> leftRow(n,0), lowerDiagonal(2*n-1,0), upperDiagonal(2*n-1,0);
        solve(0, n, leftRow, lowerDiagonal, upperDiagonal);
        return result;
    }
};