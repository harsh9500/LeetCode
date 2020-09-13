class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        auto index=lower_bound(intervals.begin(),intervals.end(),newInterval);
        intervals.insert(index,newInterval);
        vector<int> temp=intervals[0];
        for(auto interval:intervals)
        {
            if(interval[0]<=temp[1])
            {
                temp[1]=max(temp[1],interval[1]);
            }
            else
            {
                answer.push_back(temp);
                temp=interval;
            }
        }
        answer.push_back(temp);
        return answer;
    }
};