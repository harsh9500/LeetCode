class Solution {
public:
    bool isFound(vector<vector<char> > &board, int x, int y, int m, int n, int i,string word)
    {
        if (i==word.length()) return true;
        if(x<0 || y<0 || x>=m || y>=n || board[x][y]=='\0' || word[i]!=board[x][y])
            return false;
        char t=board[x][y];
        board[x][y]='\0';
        if(isFound(board,x-1,y,m,n,i+1,word) || 
           isFound(board,x+1,y,m,n,i+1,word) || 
           isFound(board,x,y-1,m,n,i+1,word) ||
           isFound(board,x,y+1,m,n,i+1,word)
          )
            return true; 
        board[x][y]=t;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        if(n==0)
            return false;
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isFound(board,i,j,n,m,0,word))
                    return true;
            }
        }
        return false;
    }
};