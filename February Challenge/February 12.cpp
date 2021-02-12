class Solution {
public:
    int numberOfSteps (int num) {
        int answer=0;
        while(num!=0)
        {
            answer++;
            num=(num%2==0?num/2:num-1);
        }
        return answer;
    }
};