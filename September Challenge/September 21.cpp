class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        if(n<1)
            return true;
        int currCapacity=0;
        vector<int> temp(1001,0);
        for(int i=0;i<n;i++)
        {
            int passengers=trips[i][0];
            temp[trips[i][1]]+=passengers;
            temp[trips[i][2]]-=passengers;
        }
        for(int i=0;i<1000;i++)
        {
            currCapacity+=temp[i];
            if(currCapacity>capacity)
                return false;
        }
        return true;
    }
};