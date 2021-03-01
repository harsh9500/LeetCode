class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        n/=2;
        unordered_set<int> s;
        for(int x:candyType)
            s.insert(x);
        int size=s.size();
        return min(n,size);
    }
};