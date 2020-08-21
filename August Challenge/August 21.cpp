class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n=A.size();
        int left=0,right=n-1;
        while(left<right)
        {
            while(left<right && (A[left]%2==0))
                left++;
            while(left<right && (A[right]%2==1))
                right--;
            if(left<right)
            {
                swap(A[left++],A[right--]);
            }
        }
        return A;
    }
};