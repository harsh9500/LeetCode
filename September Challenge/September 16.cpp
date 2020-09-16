class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max=0, mask=0;
        set<int> s;
        for(int i=31;i>=0;i--)
        {
            mask=mask | (1<<i);
            s.clear();
            for(int num:nums)
            {
                s.insert(num & mask);
            }
            int temp=max | (1<<i);
            for(int ele:s)
            {
                if(s.find(ele^temp)!=s.end())
                {
                    max=temp;
                    break;
                }
            }
        }
        return max;
    }
};