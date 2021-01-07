class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int ans=0;
        vector<int> index(128,-1);
        for(int i=0,j=0;j<n;j++)
        {
            i=max(index[s[j]],i);
            ans=max(ans,j-i+1);
            index[s[j]]=j+1;
        }
        return ans;
    }
};