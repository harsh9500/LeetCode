class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse=n;
        uint32_t count=31;
        n>>=1;
        while(n)
        {
            reverse<<=1;
            reverse|=(n&1);
            n>>=1;
            count--;
        }
        reverse<<=count;
        return reverse;
    }
};