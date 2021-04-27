class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        double l = log10(n)/log10(3);
        if(floor(l)==ceil(l))
            return true;
        return false;
    }
};