class Solution {
public:
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &answer, vector<int> &leftRow,
              vector<int> &lowerDiagonal, vector<int> &upperDiagonal)
    {
        if(col==n)
        {
            answer.push_back(board);
            return;
        }
        for(int row=0; row<n; row++)
        {
            if(board[row][col] != 'Q' && leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0)
            {
                board[row][col]='Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, n, board, answer, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col]='.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<string> board;
        vector<int> leftRow(n,0), lowerDiagonal(2*n-1,0), upperDiagonal(2*n-1,0);
        string s(n,'.');
        for(int i=0; i<n; i++)
            board.push_back(s);
        solve(0, n, board, answer, leftRow, lowerDiagonal, upperDiagonal);
        return answer;
    }
};