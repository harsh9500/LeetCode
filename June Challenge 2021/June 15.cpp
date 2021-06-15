class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();

        long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0l);
        if (sum % 4)
            return false;
        long sideLen = sum / 4;

        vector<int> usedMasks;
        // validHalfSubsets[i] == true iff the subset represented by bitmask i
        // has sum == 2*sideLen, AND the subset represented by i can be further partitioned into
        // two equal subsets. See below for how it is used.
        vector<bool> validHalfSubsets(1<<n, false);

        int all = (1 << n) - 1;
        for (int mask = 0; mask <= all; mask++) {
            long subsetSum = 0;
            for (int i = 0; i < 32; i++) {
            if ((mask >> i) & 1)
            subsetSum += matchsticks[i];
            }
        if (subsetSum == sideLen) {
            for (int usedMask : usedMasks) {
                if ((usedMask & mask) == 0) {
                    int validHalf = usedMask | mask;
                    validHalfSubsets[validHalf] = true;

                    if (validHalfSubsets[all ^ validHalf])
                        return true;
                    }
                }
            usedMasks.push_back(mask);
            }
        }
        return false;
    }
};