class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            answer^=nums[i];
        return answer;
    }
};