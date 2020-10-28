class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> answer;
        if(n==0)
            return answer;
        for(int i=0;i<n;i++)
        {
            int digit=nums[i];
            while(i+1<n && nums[i+1]==nums[i]+1)
                i++;
            if(digit!=nums[i])
                answer.push_back(to_string(digit)+"->"+to_string(nums[i]));
            else
                answer.push_back(to_string(digit));
        }
        return answer;
    }
};