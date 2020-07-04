class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0)
            return 0;
        long int value=1;
        queue<long int> q2;
        queue<long int> q3;
        queue<long int> q5;
        q2.push(2);
        q3.push(3);
        q5.push(5);
        n-=1;
        while(n>0)
        {
            value=min(q2.front(),min(q3.front(),q5.front()));
            if(value==q5.front())
            {
                q5.pop();
            }
            else
            {
                if(value==q3.front())
                {
                    q3.pop();
                }
                else
                {
                    q2.pop();
                    q2.push(value*2);
                }
                q3.push(value*3);
            }
            q5.push(value*5);
            n--;
        }
        return value;
    }
};