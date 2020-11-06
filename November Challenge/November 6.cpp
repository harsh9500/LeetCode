class Solution {
public:
    int computeSum(vector<int> nums, int x) {
        long int s=0;
        for (int n : nums)
        {
            s+=(n/x)+(n%x==0?0:1); 
        }
        return s;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=nums[nums.size()-1];
        while (left<=right)
        {
            int pivot=left+((right-left)>>1);
            int num=computeSum(nums,pivot);
            if (num>threshold)
            {
                left=pivot+1;    
            }
            else
            {
                right=pivot-1;    
            }    
        }
        return left;
    }
};