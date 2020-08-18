class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> answer;
        for(int i=1;i<10;i++)
            answer.push_back(i);
        answer.push_back(0);
        if(N==1)
            return answer;
        answer.pop_back();
        int temp;
        for(int level=1;level<N;level++)
        {
            vector<int> next;
            for(auto num:answer)
            {
                int tail=num%10;
                temp=tail+K;
                if(temp>=0 && temp<10)
                {
                    next.push_back(num*10+temp);
                }
                if(K!=0)
                {
                    temp=tail-K;
                    if(temp>=0 && temp<10)
                    {
                        next.push_back(num*10+temp);
                    }
                }
            }
            answer=next;
        }
        return answer;
    }
};