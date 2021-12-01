/**
* Leetcode 5. Longest Palindromic Substring
* https://leetcode.com/problems/longest-palindromic-substring/
*/

#include <string>

using namespace std;

class Solution {
private:
    string longest = "";
public:
    void checkFromMiddle(string &s, int left, int right) {
        while (left > 0 && right < s.size() && (s[left] == s[right])) {
            left--; 
            right++;
        }
        if (left+1 == right && s[left] != s[right]) {
            return;
        }
        if (s[left] != s[right]){
            right--; left++;
        }
        
        int length = right - left + 1;
        if (length > longest.size()) {
            longest = s.substr(left, length);
        }
    }

    string longestPalindrome(string s) {
        if (s.size() == 1)
            return s;
        if (s.size() == 0)
            return "";

        for (size_t i = 0; i < s.size(); i++) {
            checkFromMiddle(s, i, i);
            checkFromMiddle(s, i, i+1);
        }
        
        return longest;
    }
};

int main() {
    string test = "babad";
    Solution().longestPalindrome(test);

    return 0;
}