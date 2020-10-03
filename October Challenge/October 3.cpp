class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0 ||k<0)
            return 0;
        unordered_map<int,int> m;
        int count=0;
        for(auto i:nums)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            if(k==0)
            {
                if(i.second>=2)
                    count++;
            }
            else
            {
                if(m.find(i.first+k)!=m.end())
                    count++;
            }
        }
        return count;
    }
};