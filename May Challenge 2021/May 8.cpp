class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        istringstream issl (left);
        long L;
        issl >> L;
        // long R = stoi(right);
        istringstream issr (right);
        long R;
        issr >> R;
        
        int MAGIC = 100000;
        int ans = 0;

        for (int k = 1; k < MAGIC; ++k) {
            string sb = to_string(k);
            for (int i = sb.length() - 2; i >= 0; --i)
                sb+=sb[i];
            long v = stoi(sb);
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }

        for (int k = 1; k < MAGIC; ++k) {
            string sb = to_string(k);
            for (int i = sb.length() - 1; i >= 0; --i)
                sb+=sb[i];
            long v = stoi(sb);
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }

        return ans;
    }

    bool isPalindrome(long x) {
        return x == reverse(x);
    }

    long reverse(long x) {
        long ans = 0;
        while (x > 0) {
            ans = 10 * ans + x % 10;
            x /= 10;
        }

        return ans;
    }
};