class Solution {
public:
    int result = INT_MIN;
    void updateResult(vector<int>& nums, int k) {
        int sum = 0;

        set<int> sortedSum;
        set<int>::iterator it;

        sortedSum.insert(0);
        for (int& num : nums) {
            sum += num;

            it = sortedSum.lower_bound(sum - k);

            if (it != sortedSum.end())
                result = max(result, sum - *it);
            sortedSum.insert(sum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix[0].size() > matrix.size()) {
            vector<int> rowSum(matrix[0].size());
            for (int i = 0; i < matrix.size(); i++) {
                fill(rowSum.begin(), rowSum.end(), 0);
                for (int row = i; row < matrix.size(); row++) {
                    for (int col = 0; col < matrix[0].size(); col++)
                        rowSum[col] += matrix[row][col];

                    updateResult(rowSum, k);

                    if (result == k)
                        return result;
                }
            }
        } else {
            vector<int> colSum(matrix.size());
            for (int i = 0; i < matrix[0].size(); i++) {
                fill(colSum.begin(), colSum.end(), 0);
                for (int col = i; col < matrix[0].size(); col++) {
                    for (int row = 0; row < matrix.size(); row++)
                        colSum[row] += matrix[row][col];

                    updateResult(colSum, k);
                    if (result == k)
                        return result;
                }
            }
        }
        return result;
    }
};