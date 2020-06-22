class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ones=0,twos=0,notThrees,x;
        for(int i=0;i<n;i++)
        {
            x=nums[i];
            twos|=(ones&x);
            ones^=x;
            notThrees=~(ones&twos);
            ones&=notThrees;
            twos&=notThrees;
        }
        return ones;
    }
};