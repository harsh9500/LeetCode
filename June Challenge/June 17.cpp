class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m, vector<vector<bool>>& visited)
    {
        if(i<0 || j<0 || i>n-1 || j>m-1 || visited[i][j] || board[i][j]=='X')
            return;
        visited[i][j]=true;
        dfs(board,i+1,j,n,m,visited);
        dfs(board,i-1,j,n,m,visited);
        dfs(board,i,j+1,n,m,visited);
        dfs(board,i,j-1,n,m,visited);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        if(n==0)
            return;
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int j=0;j<m;j++)
        {
            dfs(board,0,j,n,m,visited);
        }
        for(int j=0;j<m;j++)
        {
            dfs(board,n-1,j,n,m,visited);
        }
        for(int i=0;i<n;i++)
        {
            dfs(board,i,0,n,m,visited);
        }
        for(int i=0;i<n;i++)
        {
            dfs(board,i,m-1,n,m,visited);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && visited[i][j]==false)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};