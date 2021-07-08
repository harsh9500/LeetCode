class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size(), m = nums2.size();
        int memo [n + 1][m + 1];
        memset(memo,0,sizeof(memo));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (nums1[i] == nums2[j])
                {
                    memo[i][j] = memo[i+1][j+1] + 1;
                    if (ans < memo[i][j])
                        ans = memo[i][j];
                }
            }
        }
        return ans;
    }
};