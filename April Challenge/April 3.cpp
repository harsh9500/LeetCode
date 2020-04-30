class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum=nums[0];
        int maxsofar=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            currentsum=max(currentsum+nums[i],nums[i]);
            maxsofar=max(maxsofar,currentsum);
        }
        return maxsofar;
    }
};