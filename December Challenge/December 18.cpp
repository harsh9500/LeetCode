class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=INT_MAX, j=INT_MAX;
        for(auto ele:nums)
        {
            if(ele<=i)
            {
                i=ele;
            }
            else
            {
                if(ele<=j)
                    j=ele;
                else
                    return true;
            }
        }
        return false;
    }
};