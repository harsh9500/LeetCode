class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size()/2;
        int answer=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto v:costs)
        {
            answer+=v[0];
            pq.push(v[1]-v[0]);
        }
        while(n>0)
        {
            answer+=pq.top();
            pq.pop();
            n--;
        }
        return answer;
    }
};