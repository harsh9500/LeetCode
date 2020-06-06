class Solution {
public:
    static bool compare(const vector<int> a, const vector<int> b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        if(n<=1)
            return people;
        sort(people.begin(),people.end(),compare);
        vector<vector<int>> answer;
        for(int i=n-1;i>=0;i--)
            answer.insert(answer.begin()+people[i][1],people[i]);
        return answer;
    }
};