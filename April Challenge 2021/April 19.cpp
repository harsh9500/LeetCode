class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int comb[target+1];
        memset(comb,0,sizeof(comb));
        comb[0]=1;
        for (int i=1;i<=target;i++)
        {
            for (int j=0;j<nums.size();j++)
            {
                if (i-nums[j]>=0)
                {
                    comb[i]+=comb[i - nums[j]];
                }
            }
        }
        return comb[target];
    }
};