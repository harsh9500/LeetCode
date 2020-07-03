class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N=(N-1)%14;
        for(N=N+1;N>0;N--)
        {
            vector<int> temp(8,0);
            for(int i=1;i<7;i++)
                temp[i]=(cells[i-1]==cells[i+1]?1:0);
            cells=temp;
        }
        return cells;
    }
};