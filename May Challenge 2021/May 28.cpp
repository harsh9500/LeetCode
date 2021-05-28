class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> s;

    int sum = 0, ans = 0, i = 0, j = 0, n = nums.size();

    while(i<n && j<n)
    {

        if(s.find(nums[j])==s.end())
        {

            sum+=nums[j];
            ans = max(sum,ans);
            s.insert(nums[j++]);
        }
        else
        {

            sum = sum-nums[i];
            s.erase(nums[i++]);
        }
    }
    return ans; 
    }
};