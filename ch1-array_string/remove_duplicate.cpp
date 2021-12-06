/**
* Leetcode 316
* https://leetcode.com/problems/remove-duplicate-letters/
*/

#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, vector<int>> occur;
        // count the occurrences
        for (int i = 0; i < s.size(); i++) {
            if (occur.find(s[i]) == occur.end()) {
                occur[s[i]] = vector<int>{i};
            }
            else {
                occur[s[i]].push_back(i);
            }
        }

        // remove the duplicate char
        for (auto iter = occur.begin(); iter != occur.end(); iter++) {
            if (iter->second.size() == 1) 
                continue;

            int remove = -1;
            for (int i : iter->second) {
                if (i+1 != s.size() && s[i] < s[i+1]) {
                    remove = i; 
                    break;
                }
            }

            if (remove == -1)
                remove = iter->second.back();
            for (int i : iter->second) {
                if (i != remove)
                    s[i] = ' ';
            }
        }
        s.erase(remove(s.begin(), s.end(), ' '), s.end());

        return s;
    }
};
