class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g=__gcd(p,q);
        p/=g;
        p%=2;
        q/=g;
        q%=2;
        if(p==1 && q==1)
            return 1;
        return p==1?0:2;
    }
};