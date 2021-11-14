/**
* Leetcode 14
* https://leetcode.com/problems/longest-common-prefix/
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            // compare the word with the current prefix
            string str = strs[i];
            for (int c = 0; c < prefix.size(); c++) {
                if (prefix[c] != str[c]) {
                    // the char is different, reduce the common prefix
                    prefix = prefix.substr(0, c);
                }
            }    
            if (prefix.size() == 0)
                break;
        }

        return prefix;
    }
};