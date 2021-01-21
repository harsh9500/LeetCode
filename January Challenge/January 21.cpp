class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack(k);
        int j = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (j && stack[j - 1] > nums[i] && j - 1 + n - i >= k)
                j--;
            if (j < k)
                stack[j++] = nums[i];
        }
        return stack;
    }
};