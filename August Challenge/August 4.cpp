class Solution {
public:
    bool isPowerOfFour(int num) {
        // if(num==1)
        //     return true;
        // if(num&1)
        //     return false;
        // int count=0,position=1;
        // for(int i=0;i<32;i++)
        // {
        //     if(num&(1<<i))
        //     {
        //         if(count>1)
        //             return false;
        //         count++;
        //         position=i;
        //     }
        // }
        // return (count==1 && (position%2==0));
        
        // return num>0 && (num&(num-1))==0 && (num & 0x55555555)==num;
        
        return num>0 && (num&(num-1))==0 && (num-1)%3==0;
    }
};