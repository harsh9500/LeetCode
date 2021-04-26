class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> p;
        int n=heights.size();
        for(int i=0; i<n-1; i++)
        {
            int diff=heights[i+1]-heights[i];
            if(diff>0)
            {
                p.push(-diff);
            }
            if(p.size()>ladders)
            {
                bricks+=p.top();
                p.pop();
            }
            if(bricks<0)
                return i;
        }
        return n-1;
    }
};