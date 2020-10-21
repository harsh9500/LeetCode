class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (int i : asteroids)
        {
            while (!s.empty() && s.back() > 0 && s.back() < -i)
                s.pop_back();
            if (s.empty() || i > 0 || s.back() < 0)
                s.push_back(i);
            else if (i < 0 && s.back() == -i)
                s.pop_back();
        }
        return s;
    }
};