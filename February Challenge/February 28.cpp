class FreqStack {
public:
    unordered_map<int,int> f;
    unordered_map<int,stack<int>> g;
    int maxFrequency;
    FreqStack() {
        maxFrequency=0;
    }
    
    void push(int x) {
        int fr=0;
        if(f.find(x)!=f.end())
            fr=f[x];
        fr++;
        f[x]=fr;
        if(fr>maxFrequency)
            maxFrequency=fr;
        if(g.find(fr)!=g.end())
        {
            g[fr].push(x);
        }
        else
        {
            stack<int> s;
            s.push(x);
            g[fr]=s;
        }
    }
    
    int pop() {
        int x=g[maxFrequency].top();
        g[maxFrequency].pop();
        f[x]=f[x]-1;
        if(g[maxFrequency].empty())
            maxFrequency--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */