class Solution {
public:
    int minOperations(int n) {
        int cnt = n / 2;
        return cnt * (cnt + n % 2);
    }
};