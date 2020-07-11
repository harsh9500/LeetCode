class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> temp;
        int n=nums.size();
        for(int i=0;i<(int)pow(2,n);i++)
        {
            temp.clear();
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))!=0)
                {
                    temp.push_back(nums[j]);
                }
            }
            answer.push_back(temp);
        }
        return answer;
    }
};