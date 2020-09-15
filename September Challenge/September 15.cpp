class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream stream (s);
        string temp,last;
        unsigned long answer=0;
        while(getline(stream,temp,' '))
        {
            if(temp!="")
                last=temp;
        }
        answer=last.length();
        return answer; 
    }
};