class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for (int num:nums)
            totalSum+=num;
        if (totalSum%2 != 0)
            return false;
        int subSetSum=totalSum/2;
        vector<bool> dp(subSetSum+1,false);
        dp[0]=true;
        for (int curr:nums)
        {
            for (int j=subSetSum;j>=curr;j--)
            {
                dp[j] = dp[j] || dp[j-curr];
            }
        }
        return dp[subSetSum];
    }
};