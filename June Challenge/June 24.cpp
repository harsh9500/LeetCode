class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n==1)
            return 1;
        
        // DP-based solution
        // vector<long long int> G(n+1,0);
        // G[0]=1;
        // G[1]=1;
        // for(int i=2; i<=n; ++i)
        // {
        //     for(int j=1; j<=i; ++j)
        //     {
        //         G[i]+=G[j-1]*G[i-j];
        //     }
        // }
        // return G[n];
        
        long long int catalan=1;
        for(int i=0;i<n;i++)
        {
            catalan*=(2*n-i);
            catalan/=(i+1);
        }
        return catalan/(n+1);
    }
};