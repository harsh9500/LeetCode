class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            xor1^=nums[i];
        }
        for(int i=0;i<=n;i++)
        {
            xor1^=i;
        }
        return xor1;
    }
};