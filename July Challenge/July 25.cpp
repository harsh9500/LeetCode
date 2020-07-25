class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(),nums.end());
    }
};
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1)
//             return nums[0];
//         int l=0,r=n-1,mid;
//         while(l<r)
//         {
//             mid=l+(r-l)/2;
//             if(nums[mid]>nums[r])
//                 l=mid+1;
//             else
//                 if(nums[mid]<nums[r])
//                     r=mid;
//                 else
//                     r--;
//         }
//         return nums[l];
//     }
// };