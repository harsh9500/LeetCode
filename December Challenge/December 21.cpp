class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n=A.size();
        sort(A.begin(),A.end());
        int ans=A[n-1]-A[0];
        
        for(int i=0;i<n-1;i++)
        {
            int a=A[i], b=A[i+1];
            int high=max(A[n-1]-K,a+K);
            int low=min(A[0]+K,b-K);
            ans=min(ans,high-low);
        }
        return ans;
    }
};