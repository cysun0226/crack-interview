/**
* Leetcode 49
* https://leetcode.com/problems/group-anagrams/
*/

#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<int, bool> grouped;
        map<int, map<char, int>> counts;
        vector<vector<string>> anagrams;
        
        for (size_t i = 0; i < strs.size(); i++) {
            // build the count map
            map<char, int> count;
            string word = strs[i];
            for (char c : word) {
                if (count.find(c) != count.end())
                    count[c]++;
                else
                    count[c] = 1;
            }
            counts[i] = count;
        }

        for (size_t i = 0; i < strs.size(); i++) {
            // ungrouped words
            if (grouped.find(i) == grouped.end()) {
                vector<string> anagram = {strs[i]};
                for (size_t w = i+1; w < strs.size(); w++) {
                    if (counts[i] == counts[w]) {
                        anagram.push_back(strs[w]);
                        grouped[w] = true;
                    }
                }
                anagrams.push_back(anagram);
            }
        }

        return anagrams;
    }
};


int main() {
    vector<string> test = {"", ""};
    Solution().groupAnagrams(test);

    return 0;
}