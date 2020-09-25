class Solution {
public:
    static bool comp(const string s1, const string s2)
    {
        string a=s1+s2;
        string b=s2+s1;
        if(b.compare(a)<0)
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int i:nums)
        {
            arr.push_back(to_string(i));
        }
        sort(arr.begin(),arr.end(),comp);
        if(arr[0]=="0")
            return "0";
        string answer="";
        for(string s:arr)
        {
            answer+=s;
        }
        return answer;
    }
};