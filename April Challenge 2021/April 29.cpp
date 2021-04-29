class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> answer{-1,-1};
        if(n==0)
            return answer;
        int low=0,high=n-1,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                int i=mid,j=mid;
                while(i>=0 && nums[i]==target)
                    i--;
                while(j<n && nums[j]==target)
                    j++;
                answer[0]=i+1;
                answer[1]=j-1;
                return answer;
            }
            if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return answer;
    }
};

