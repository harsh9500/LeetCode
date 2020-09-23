class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas=0,sumCost=0,start=0,tank=0;
        for (int i=0;i<gas.size();i++)
        {
            sumGas+=gas[i];
            sumCost+=cost[i];
            tank+=gas[i] - cost[i];
            if (tank < 0)
            {
                start=i+1;
                tank=0;
            }
        }
        if (sumGas<sumCost)
        {
            return -1;
        }
        return start;
    }
};