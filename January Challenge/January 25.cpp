class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastOne=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                if(lastOne!=-1)
                {
                    if(i-lastOne<=k)
                        return false;
                }
                lastOne=i;
            }
        }
        return true;
    }
};