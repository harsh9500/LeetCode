class Solution {
public:
    vector<string> urls;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urls.push_back(longUrl);
        return to_string(urls.size()-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urls[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));