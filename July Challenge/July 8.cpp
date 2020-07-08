class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        int n=nums.size();
        if(n<3)
            return answer;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        int j,k;
        for(int i=0;i<n-2;i++)
        {
            if (i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                j=i+1;
                k=n-1;
                while(j<k)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        temp.clear();
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        answer.push_back(temp);
                        while(j<k && nums[j] == nums[j+1])
                            j++;
                        while(j<k && nums[k] == nums[k-1])
                            k--;
                        j++;
                        k--;
                    }
                    else
                    {
                        if(nums[i]+nums[j]+nums[k]>0)
                            k--;
                        else
                            j++;
                    }
                }
            }
            
        }
        return answer;
    }
};