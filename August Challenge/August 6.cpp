class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer;
        int index;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]<0)
                answer.push_back(abs(nums[i]));
            else
                nums[abs(nums[i])-1]*=-1;
        }
        return answer;
    }
};