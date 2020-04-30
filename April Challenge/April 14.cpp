class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left=0,right=0;
        int count;
        int n=shift.size();
        for(int i=0;i<n;i++)
        {
            if(shift[i][0]==0)
                left+=shift[i][1];
            else
                right+=shift[i][1];
        }
        if(left==right)
        {
            return s;
        }
        if(left>right)
        {
            count=(left-right)%s.length();
        }
        else
        {
            count=s.length()-((right-left)%s.length());
        }
        reverse(s.begin(),s.begin()+count);
        reverse(s.begin()+count,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};