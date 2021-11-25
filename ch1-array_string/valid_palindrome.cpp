/*
* Leetcode 125. Valid Palindrome
* https://leetcode.com/problems/valid-palindrome/
*/

#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // removing all non-alphanumeric characters, and convert to lowercase
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !(isalpha(c) || isdigit(c)); } ), s.end());
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return tolower(c);});

        // check if the reversed result is the same
        bool is_pal = true;
        int last = s.size()-1;
        for (size_t i = 0; i < s.size()/2; i++) {
            if (s[i] != s[last-i]) {
                is_pal = false;
                break;
            }
        }

        return is_pal;

        /* str::reverse() */
        // string rev_s = s;
        // reverse(rev_s.begin(), rev_s.end());
        // return (s == rev_s);
    }
};

int main() {
    vector<string> test_cases;
    test_cases.push_back("A man, a plan, a canal: Panama");
    test_cases.push_back("race a car");

    for (string s : test_cases) {
        cout << "[str] " << s << endl;
        cout << Solution().isPalindrome(s) << endl;
    }

    return 0;
}