class Solution {
public:
    int nextGreaterElement(int n) {
        if(n==INT_MAX)
            return -1;
        string s=to_string(n);
        int len=s.length();
        int i=len-1;
        while(i>0)
        {
            if(s[i-1]<s[i])
                break;
            i--;
        }
        if(i==0)
            return -1;
        int pivot=s[i]-'0', pivotindex=i-1, index=i, ele=s[i-1]-'0';
        
        while(i<len)
        {
            if(s[i]-'0'<=pivot && s[i]-'0'>ele)
            {
                pivot=s[i]-'0';
                index=i;
            }
            i++;
        }
        swap(s[index],s[pivotindex]);
        reverse(s.begin()+pivotindex+1,s.end());
        istringstream iss(s);
        iss>>n;
        return n<INT_MAX?n:-1;
    }
};