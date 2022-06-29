// LeetCode 535 TinyURL 的加密与解密

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    unordered_map<int, string> db;

   public:
    Solution() { srand(time(nullptr)); }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int key = 0;
        do {
            key = rand();
        } while (db.count(key));
        db[key] = longUrl;
        return "http://tinyurl.com/" + to_string(key);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t pos = shortUrl.rfind('/') + 1;
        int key = stoi(shortUrl.substr(pos, int(shortUrl.size()) - pos));
        return db[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));