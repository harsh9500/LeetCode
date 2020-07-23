class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> answer(2,0);
        int diff=0;
        for(auto x:nums)
        {
            diff^=x;
        }
        diff &= -diff;
        for(auto x:nums)
        {
            if((x&diff)==0)
                answer[1]^=x;
            else
                answer[0]^=x;
        }
        return answer;
    }
};