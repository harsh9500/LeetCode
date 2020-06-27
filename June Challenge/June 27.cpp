class Solution {
public:
    int numSquares(int n) {
        if(n<=0)
            return 0;
        vector<int> perfsquares(n+1,INT_MAX);
        perfsquares[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                perfsquares[i]=min(perfsquares[i],perfsquares[i-j*j]+1);
            }
        }
        return perfsquares[n];
    }
};