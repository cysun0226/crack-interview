/**
* Leetcode 49
* https://leetcode.com/problems/group-anagrams/
*/

#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams_bf(vector<string>& strs) {
        vector<bool> grouped(strs.size(), false);
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
            if (!grouped[i]) {
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

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<int, string> ingredients; // <index, sorted string>
        map<string, vector<string>> groups;
        vector<vector<string>> anagrams;
        
        for (size_t i = 0; i < strs.size(); i++) {
            // build the sorted str map
            string ingr = strs[i];
            sort(ingr.begin(), ingr.end());
            ingredients[i] = ingr;
        }

        for (size_t i = 0; i < strs.size(); i++) {
            // ungrouped words
            if (groups.find(ingredients[i]) == groups.end()) {
                vector<string> new_group = {strs[i]};
                groups[ingredients[i]] = new_group;
            }
            else {
                groups[ingredients[i]].push_back(strs[i]);
            }
        }

        for (auto iter = groups.begin(); iter != groups.end(); iter++) {
            anagrams.push_back(iter->second);
        }

        return anagrams;
    }
};


int main() {
    vector<string> test = {"", ""};
    Solution().groupAnagrams(test);

    return 0;
}