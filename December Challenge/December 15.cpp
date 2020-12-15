class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n,0);
        int i=0,j=n-1;
        for(int k=n-1;k>=0;k--)
        {
            if(abs(nums[i])>abs(nums[j]))
            {
                answer[k]=nums[i]*nums[i];
                i++;
            }
            else
            {
                answer[k]=nums[j]*nums[j];
                j--;
            }
        }
        return answer;
    }
};