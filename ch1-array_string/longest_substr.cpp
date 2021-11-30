/**
* Leetcode 3. Longest Substring Without Repeating Characters
* https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> count;
        int max_length = 0;

        for (size_t i = 0; i < s.size(); i++) {
            auto iter = count.find(s[i]);
            if (iter == count.end()) {
                count[s[i]] = i;
                if (count.size() > max_length) max_length = count.size();
            }
            else {
                // remove the chars until the last repeating
                int rep_idx = iter->second, longest_size = count.size();
                for (size_t j = i-longest_size; j < rep_idx; j++) {
                    count.erase(s[j]);
                }
                count[s[i]] = i;
            }
        }
        
        return max_length;
    }
};

int main() {
    // string test = "abcabcbb";
    string test = "umvejcuuk";
    Solution().lengthOfLongestSubstring(test);

    return 0;
}