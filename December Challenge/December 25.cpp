class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        if (n == 0)
        {
            return {};
        }
        
        const int m = matrix[0].size();
        vector<vector<int>> diagonals(n + m - 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                diagonals[i + j].push_back(matrix[i][j]);
            }
        }
        
        int dir = 0;
        vector<int> diagonalOrder;
        for (int i = 0; i < diagonals.size(); i++)
        {
            if (dir % 2 == 0)
            {
                for (int j = diagonals[i].size() - 1; j >= 0 ; j--)
                {
                    diagonalOrder.push_back(diagonals[i][j]);
                } 
            }
            else
            {
                for (int j = 0; j < diagonals[i].size(); j++)
                {
                    diagonalOrder.push_back(diagonals[i][j]);
                } 
            }      
            
            dir++;
        }
        
        return diagonalOrder;

    }
};