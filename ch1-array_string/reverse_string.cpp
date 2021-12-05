/**
* Leetcode 344. Reverse String
* https://leetcode.com/problems/reverse-string/
*/

#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size()/2; i++){
            char tmp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = tmp;
        }
    }

    void doublePointer(char* s, int sSize) {
        char *end = s + sSize - 1, tmp;
        while (s < end) {
            tmp = *s;
            *s++ = *end;
            *end-- = tmp;
        }
    }
};

