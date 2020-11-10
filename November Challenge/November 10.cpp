class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n=A.size();
        for(auto &row:A)
        {
            reverse(row.begin(),row.end());
            for(int i=0;i<n;i++)
            {
                if(row[i]==0)
                    row[i]=1;
                else
                    row[i]=0;
            }
        }
        return A;
    }
};