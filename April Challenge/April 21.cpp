/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        // BinaryMatrix binaryMatrix = new BinaryMatrix();
        vector<int> dim = binaryMatrix.dimensions();
        int n=dim[0],m=dim[1];
        int ans=-1;
        // int low,high,mid;
        // for(int i=0;i<n;i++)
        // {
        //     low=0,high=m-1;
        //     while(low<=high)
        //     {
        //         mid=low+(high-low)/2;
        //         if(binaryMatrix.get(i,mid)==0)
        //         {
        //             low=mid+1;
        //         }
        //         else
        //         {
        //             if(ans==-1)
        //                 ans=mid;
        //             else
        //                 ans=min(ans,mid);
        //             high=mid-1;
        //         }
        //     }
        // }
        int p=m-1,q=0;
        while(p>=0 && q<n)
        {
            if(binaryMatrix.get(q,p)==0)
            {
                q++;
            }
            else
            {
                ans=p;
                p--;
            }
        }
        return ans;
    }
};