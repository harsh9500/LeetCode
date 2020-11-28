class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        deque<int> q;
        int n=nums.size();
        int i=0;
        for(i=0;i<k;i++)
        {
            while(!q.empty() && nums[i]>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        for(;i<n;i++)
        {
            answer.push_back(nums[q.front()]);
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
            while(!q.empty() && nums[i]>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        answer.push_back(nums[q.front()]);
        return answer;
    }
};