class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;
        unordered_set<int> s;
        int n=nums.size();
        int count1=0,count2=0,majority1=-1,majority2=-1;
        for(int i:nums)
        {
            if(i==majority1)
                count1++;
            else
            {
                if(i==majority2)
                    count2++;
                else
                {
                    if(count1==0)
                    {
                        majority1=i;
                        count1++;
                    }
                    else
                    {
                        if(count2==0)
                        {
                            majority2=i;
                            count2++;
                        }
                        else
                        {
                            count1--;
                            count2--;
                        }
                    }
                }
            }
        }
        count1=count2=0;
        for(int i:nums)
        {
            if(majority1==i)
            {
                count1++;
                if(count1>n/3)
                    s.insert(i);
            }
            else
            {
                if(majority2==i)
                {
                    count2++;
                    if(count2>n/3)
                        s.insert(i);
                }
            }
        }
        for(int ele:s)
            answer.push_back(ele);
        return answer;
    }
};