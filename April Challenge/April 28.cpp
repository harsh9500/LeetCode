class FirstUnique {
public:
    unordered_map<int, int > map;
    list<int> li;
    FirstUnique(vector<int>& nums) {
        for(auto i:nums)
        {
            add(i);    
        }
    }
    
    int showFirstUnique() {
        if(li.empty())
            return -1;
        while(!li.empty() && map[li.front()]>1)
            li.pop_front();
        if(li.empty())
            return -1;
        return li.front();
    }
    
    void add(int value) {
        if(map.find(value)!=map.end())
        {
            map[value]+=1;
        }
        else
        {
            map[value]=1;
        }
        li.push_back(value);
    }

};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */