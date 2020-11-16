class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n=A.size();
        int ans=0,base=0;
        while (base<n)
        {
            int end=base;
            if (end+1<n && A[end]<A[end+1])
            {
                while(end+1<n && A[end]<A[end + 1])
                    end++;

                if (end+1<n && A[end]>A[end+1])
                {
                    while (end+1<n && A[end]>A[end+1])
                        end++;
                    ans=max(ans,end-base+1);
                }
            }
            base=max(end,base+1);
        }
        return ans;
    }
};