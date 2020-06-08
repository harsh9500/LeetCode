class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        if(floor(log2(n))==ceil(log2(n)))
            return true;
        return false;
    }
};