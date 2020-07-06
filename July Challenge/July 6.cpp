class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i,carry=0;
        if(digits[n-1]==9)
        {
            digits[n-1]=0;
            carry=1;
            
            for(i=n-2;i>=0;i--)
            {
                if(digits[i]==9)
                {
                    digits[i]=0;
                }
                else
                {
                    digits[i]++;
                    break;
                }
            }
            if(i==-1)
            {
                digits.insert(digits.begin(),1);
            }
        }
        else
        {
            digits[n-1]++;
        }
        return digits;
    }
};