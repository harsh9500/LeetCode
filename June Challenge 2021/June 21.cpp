class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        vector<int> row;
        row.push_back(1);
        triangle.push_back(row);
        for(int i=1;i<numRows;i++)
        {
            vector<int> prevRow=triangle[i-1];
            row.clear();
            row.push_back(1);
            for(int j=1;j<i;j++)
            {
                row.push_back(prevRow[j]+prevRow[j-1]);
            }
            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle;
    }
};