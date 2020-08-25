class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int> dd(days.begin(),days.end());
        int cost[366];
        memset(cost,0,sizeof(cost));
        int one=costs[0],seven=costs[1],thirty=costs[2];
        for(int i=1;i<=365;i++)
        {
            cost[i]=cost[i-1];
            if(dd.find(i)!=dd.end())
            {
                cost[i] = min(cost[i-1>=0?i-1:0]+one,min(seven+cost[i-7>=0?i-7:0],thirty+cost[i-30>=0?i-30:0]));
            }
        }
        return cost[365];
    }
};