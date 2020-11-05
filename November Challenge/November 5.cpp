class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
        int odd=0,even=0;
        for(int i=0;i<n;i++)
        {
            if(position[i]&1)
                odd++;
            else
                even++;
        }
        return min(odd,even);
    }
};