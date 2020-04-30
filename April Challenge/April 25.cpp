class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return true;
    int goodpos=n-1;
    for(int i=n-2;i>=0;i--)
        if(i+nums[i]>=goodpos)
            goodpos=i;
    return goodpos==0;
    }
};