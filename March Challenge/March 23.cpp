class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
       int MOD=1000000007;
        long ans=0;
        sort(A.begin(),A.end());
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            int T=target-A[i];
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(A[j]+A[k]<T)
                    j++;
                else if(A[j]+A[k]>T)
                    k--;
                else if(A[j]!=A[k])
                {
                    int left=1,right=1;
                    while(j+1<k && A[j]==A[j+1])
                    {
                        left++;
                        j++;
                    }
                    while(k-1>j && A[k]==A[k-1])
                    {
                        right++;
                        k--;
                    }
                    ans+=left*right;
                    ans%=MOD;
                    j++;
                    k--;
                }
                else
                {
                    ans+=(k-j+1)*(k-j)/2;
                    ans%=MOD;
                    break;
                }
            }
        }
        return (int)ans;
    }
};