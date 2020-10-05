class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        int digits=floor(log2(N))+1;
        long int xorval=1<<digits;
        return (xorval-1)^N;
    }
};