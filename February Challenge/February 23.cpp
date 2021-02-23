class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)
            return false;
        int n=matrix[0].size();
        if(n==0)
            return false;
        
        // int low,high,mid;
        // for(int i=0;i<m;i++)
        // {
        //     if(matrix[i][0]>target)
        //         return false;
        //     if(matrix[i][n-1]<target)
        //         continue;
        //     low=0,high=n-1;
        //     while(low<=high)
        //     {
        //         mid=low+(high-low)/2;
        //         if(matrix[i][mid]==target)
        //             return true;
        //         if(matrix[i][mid]>target)
        //             high=mid-1;
        //         else
        //             low=mid+1;
        //     }
        // }
        // return false;
        
        int i=0,j=n-1;
        while(i<m && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]>target)
                j--;
            else
                i++;
        }
        return false;
    }
};