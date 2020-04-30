class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(true)
        {
            int sum=0;
            while(n>0)
            {
                int digit=n%10;
                sum+=(digit*digit);
                n/=10;
            }
            if(sum==1)
                return true;
            if(set.find(sum)!=set.end())
                return false;
            set.insert(sum);
            n=sum;
        }
    }
};