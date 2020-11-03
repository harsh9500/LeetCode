class Solution {
public:
    int maxPower(string s) {
        int n=s.length();
        vector<int> power(n,1);
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
                power[i]=power[i-1]+1;
        }
        return *max_element(power.begin(),power.end());
    }
};