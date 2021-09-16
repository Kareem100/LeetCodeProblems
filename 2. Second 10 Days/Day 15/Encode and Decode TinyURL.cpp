/*
Problem Title:  Encode and Decode TinyURL
Problem URL:    https://leetcode.com/problems/encode-and-decode-tinyurl/

Description:    TinyURL is a URL shortening service where you enter a URL 
                such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. 
                Design a class to encode a URL and decode a tiny URL.
                There is no restriction on how your encode/decode algorithm should work. 
                You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {

    private: 
        map<int, string> mp;
        int id = 0;
    
    public:
    
    // Encodes a URL to a shortened URL.
    int encode(string longUrl) {
        string sID = to_string(id);
        mp[sID] = longUrl; id++;
        return id;
    }

    // Decodes a shortened URL to its original URL.
    string decode(int shortUrl) {
        return mp[shortUrl];
    }
};