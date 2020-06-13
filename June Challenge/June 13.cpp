class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> answer;
        int n=nums.size();
        if(n==0)
            return answer;
        sort(nums.begin(),nums.end());
        vector<int> div(n,1);
        vector<int> prev(n,-1);
        int maxDivisorIndex=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(div[i]<div[j]+1)
                    {
                        div[i]=div[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if(div[maxDivisorIndex]<div[i])
                maxDivisorIndex=i;
        }
        
        int iter=maxDivisorIndex;
        while(iter>=0)
        {
            answer.push_back(nums[iter]);
            iter=prev[iter];
        }
        
        return answer;
    }
};