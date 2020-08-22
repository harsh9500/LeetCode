class Solution {
public:
    vector<vector<int>> rectangles;
    Solution(vector<vector<int>>& rects) {
        rectangles=rects;
    }
    
    vector<int> pick() {
        vector<int> answer(2,0);
        int sum=0;
        vector<int> selected;
        for(auto r:rectangles)
        {
            int area=(r[2]-r[0]+1)*(r[3]-r[1]+1);
            sum+=area;
            if(rand()%sum<area)
                selected=r;
        }
        answer[0]=rand()%(selected[2]-selected[0]+1)+selected[0];
        answer[1]=rand()%(selected[3]-selected[1]+1)+selected[1];
        return answer;
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */