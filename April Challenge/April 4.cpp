class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,count=0,n=nums.size();
        while(i<n)
        {
            if(nums[i]!=0)
            {
                nums[count]=nums[i];
                count++;
            }
            i++;
        }
        while(count<n)
        {
            nums[count]=0;
            count++;
        }
    }
};