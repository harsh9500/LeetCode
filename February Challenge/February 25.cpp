class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minval=INT_MAX, maxval=INT_MIN;
        bool flag=false;
        for (int i=1;i<nums.size();i++)
        {
            if (nums[i]<nums[i-1])
                flag=true;
            if(flag)
                minval=min(minval,nums[i]);
        }
        flag=false;
        for (int i=nums.size()-2;i>=0;i--)
        {
            if (nums[i]>nums[i+1])
                flag=true;
            if(flag)
                maxval=max(maxval,nums[i]);
        }
        int l,r;
        for (l=0;l<nums.size();l++)
        {
            if (minval<nums[l])
                break;
        }
        for (r=nums.size()-1;r>=0;r--)
        {
            if (maxval>nums[r])
                break;
        }
        return r-l<0 ?0:r-l+1;
    }
};