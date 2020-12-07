class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int> (n,0));
        int m=n;
        int i=0,j=0;
        int temp=1;
        while(i<m && j<n)
        {
            for(int l=j;l<n;l++)
            {
                matrix[i][l]=temp;
                temp++;
            }
            i++;
            
            for(int l=i;l<m;l++)
            {
                matrix[l][n-1]=temp;
                temp++;
            }
            n--;
            
            if(i<m)
            {
                for(int l=n-1;l>=j;l--)
                {
                    matrix[m-1][l]=temp;
                    temp++;
                }
                m--;
            }
            
            if(j<n)
            {
                for(int l=m-1;l>=i;l--)
                {
                    matrix[l][j]=temp;
                    temp++;
                }
                j++;
            }
        }
        return matrix;
    }
};