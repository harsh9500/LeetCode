class Solution {
public:
    string toGoatLatin(string S) {
        string answer="";
        int count=1;
        int pos;
        vector<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
        istringstream stream(S);
        string temp;
        while(getline(stream,temp,' '))
        {
            if(find(vowels.begin(),vowels.end(),temp[0])!=vowels.end())
            {
                answer+=temp;
            }
            else
            {
                answer+=temp.substr(1);
                answer+=temp[0];
            }
            answer+="ma";
            for(int i=1;i<=count;i++)
                answer+="a";
            answer+=" ";
            count++;
        }
        return answer.substr(0,answer.length()-1);
    }
};