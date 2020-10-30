class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return n;
        vector<int> lis(n,1),cnt(n,1);
        int maxLis=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(lis[j]+1>lis[i])
                    {
                        lis[i]=lis[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else
                    {
                        if(lis[j]+1==lis[i])
                        {
                            cnt[i]+=cnt[j];
                        }
                    }
                    maxLis=max(maxLis,lis[i]);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
            if(lis[i]==maxLis)
                count+=cnt[i];
        return count;
    }
};