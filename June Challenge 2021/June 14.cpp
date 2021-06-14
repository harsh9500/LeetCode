class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int answer = 0;
        sort(boxTypes.begin(),boxTypes.end(),comp);
        for(auto boxType:boxTypes)
        {
            int numberOfBoxes = min(truckSize,boxType[0]);
            truckSize -= numberOfBoxes;
            answer += numberOfBoxes * boxType[1];
            if(truckSize == 0)
                break;
        }
        return answer;
    }
};