class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0,majority;
        for(int i:nums)
        {
            if(count==0)
            {
                majority=i;
                count++;
            }
            else
            {
                if(majority!=i)
                    count--;
                else
                    count++;
            }
        }
        
        return majority;
    }
};