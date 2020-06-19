class Solution {
public:
    string answer;
    long mod=19260817;
    vector<int> hashes;
    
    string check(int mid, string S)
    {
        int n=S.length();
        if(mid==0)
            return "";
        long long current=0;
        unordered_map<int,vector<int>> hashMap;
        for(int i=0;i<mid;i++)
            current=((current*26) % mod + (S[i]-'a')) % mod;
        hashMap[current]=vector<int>(1,0);
        for(int i=mid;i<n;i++)
        {
            current=((current-(long long)hashes[mid-1] * (S[i-mid]-'a')) % mod + mod) % mod;
            current=(current*26 + (S[i]-'a')) % mod;
            if(hashMap.find(current)==hashMap.end())
            {
                hashMap[current]=vector<int>(1,i-mid+1);
            }
            else
            {
                for(auto it: hashMap[current])
                {
                    if(strcmp(S.substr(it,mid).data(),S.substr(i-mid+1,mid).data())==0)
                        return S.substr(it,mid);
                }
                hashMap[current].push_back(i-mid+1);
            }
        }
        return "";
    }
    
    string longestDupSubstring(string S) {
        answer="";
        int n=S.length();
        hashes=vector<int>(n,1);
        for(int i=1;i<n;i++)
            hashes[i]=(hashes[i-1]*26)%mod;
        int low=0,high=n,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            string res=check(mid,S);
            if(res.length()==0)
            {
                high=mid-1;
            }
            else
            {
                if(res.length()>answer.length())
                    answer=res;
                low=mid+1;
            }
        }
        return answer;
    }
};