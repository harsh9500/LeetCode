class TrieNode {
public:
    string word;
    unordered_map<char, TrieNode *> map;
    TrieNode() {
        this->word="";
    }
    
    void insert(string word) {
        TrieNode * temp = this;
        int n=word.length();
        for(int i=0;i<n;i++)
        {
            if(temp->map.find(word[i])==temp->map.end())
                temp->map[word[i]]=new TrieNode();
            temp=temp->map[word[i]];
        }
        temp->word=word;
    }
    
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m, TrieNode * root, vector<string>& answer)
    {
        char current=board[i][j];
        if(current=='#' || root->map.find(current)==root->map.end())
            return;
        root=root->map[current];
        if(root->word!="")
        {
            answer.push_back(root->word);
            root->word="";
        }
        board[i][j]='#';
        if(i>0)
            dfs(board,i-1,j,n,m,root,answer);
        if(i<n-1)
            dfs(board,i+1,j,n,m,root,answer);
        if(j>0)
            dfs(board,i,j-1,n,m,root,answer);
        if(j<m-1)
            dfs(board,i,j+1,n,m,root,answer);
        board[i][j]=current;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> answer;
        int n=board.size();
        if(n==0)
            return answer;
        int m=board[0].size();
        TrieNode* root = new TrieNode();
        for(auto word:words)
            root->insert(word);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dfs(board,i,j,n,m,root,answer);
            }
        }
        return answer;
        
    }
};