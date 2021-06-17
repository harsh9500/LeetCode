class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0, dp = 0;
        int prev = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < left)
            {
                res += dp;
            }
            else
            {
                if(nums[i] > right)
                {
                    dp = 0;
                    prev = i;
                }
                else
                {
                    if(nums[i] >= left && nums[i] <= right)
                    {
                        dp = i - prev;
                        res += dp;
                    }
                }
            }
        }
        return res;
    }
};