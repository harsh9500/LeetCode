class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int a = x == 1 ? bound : (int) (log10(bound) / log10(x));
        int b = y == 1 ? bound : (int) (log10(bound) / log10(y));
        
        unordered_set<int> powerfulIntegers;
        
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                
                int value = (int)pow(x, i) + (int)pow(y, j);
                
                if (value <= bound)
                {
                    powerfulIntegers.insert(value);
                }
                
                if (y == 1) {
                    break;
                }
            }
            
            if (x == 1) {
                break;
            }
        }
        
        return vector<int>(powerfulIntegers.begin(),powerfulIntegers.end());
    }
};