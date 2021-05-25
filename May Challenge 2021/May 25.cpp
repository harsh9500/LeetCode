class Solution {
public:
    int evaluate(int first, int second, char op)
    {
        switch(op)
        {
            case '+': return first+second;
            case '-': return first-second;
            case '*': return first*second;
            case '/': return first/second;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n=tokens.size();
        for(int i=0;i<n;i++)
        {
            int l = tokens[i].size();
            char c = l==1 ? tokens[i][0] : tokens[i][1];
            if(isdigit(c))
            {
                int number = stoi(tokens[i]);
                s.push(number);
            }
            else
            {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(evaluate(first,second,c));
            }
        }
        return s.top();
    }
};