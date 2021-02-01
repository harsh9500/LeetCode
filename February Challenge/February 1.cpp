class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
        // int sum = 0;
        // while (n != 0)
        // {
        //     sum++;
        //     n &= (n - 1);
        // }
        // return sum;
    }
};