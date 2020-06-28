class Solution {
public:
    vector<string> answer;
    map<string,multiset<string>> m;
    
    void visit(string airport)
    {
        while(m[airport].size())
        {
            string nextAirport=*m[airport].begin();
            m[airport].erase(m[airport].begin());
            visit(nextAirport);
        }
        answer.push_back(airport);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto pairs:tickets)
        {
            m[pairs[0]].insert(pairs[1]);
        }
        visit("JFK");
        return vector<string>(answer.rbegin(),answer.rend());
    }
    
};