class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        if(n==0)
            return 0;
        int low=0,high=n-1,mid,midVal;
        while(low+1<high)
        {
            mid=low+(high-low)/2;
            midVal=citations[mid];
            if(n-mid==midVal)
                return midVal;
            if(n-mid>midVal)
            {
                low=mid;
            }
            else
            {
                high=mid;
            }
        }
        if (citations[low]>=n-low) {
            return n-low;
        }
         
        if (citations[high]>=n-high) {
            return n-high;
        }
        return 0;
    }
};