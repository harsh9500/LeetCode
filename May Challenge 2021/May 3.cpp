class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer;
        int n=nums.size();
        answer.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            answer.push_back(answer[i-1]+nums[i]);
        }
        return answer;
    }
};