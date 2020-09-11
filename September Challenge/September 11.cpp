class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int answer=nums[0];
        int maxEndHere=answer,minEndHere=answer;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
                swap(maxEndHere, minEndHere);
            maxEndHere=max(nums[i],maxEndHere*nums[i]);
            minEndHere=min(nums[i],minEndHere*nums[i]);
            
            answer=max(maxEndHere,answer);
        }
        return answer;
    }
};