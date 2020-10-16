class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0)
            return false;
        int m=matrix[0].size();
        int low=0,high=(n*m-1),mid;
        bool flag=false;
        while(low<=high)
        {
            mid=(low+(high-low)/2);
            if(matrix[mid/m][mid%m]==target)
            {
                flag=true;
                break;
            }
            if(matrix[mid/m][mid%m]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return flag;
    }
};