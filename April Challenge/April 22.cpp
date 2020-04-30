class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_map<int,int> map;
        int sum=0,count=0;;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)
                count++;
            if(map.find(sum-k)!=map.end())
                count+=map[sum-k];
            map[sum]++;
        }
        return count;
    }
};