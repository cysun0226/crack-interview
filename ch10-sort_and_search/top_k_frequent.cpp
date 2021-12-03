/**
* Leetcode 347
* https://leetcode.com/problems/top-k-frequent-elements/
*/

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
// private:
    // typedef map<int, int> F_MAP;

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;

        // count the frequencies
        for (int i : nums) {
            if (frequency.find(i) == frequency.end())
                frequency[i] = 1;
            else
                frequency[i]++;
        }

        // sort by the counted value
        vector<pair<int, int>> sorted_frequency;
        for (const auto &item : frequency) {
            sorted_frequency.push_back(item);
        }
        auto cmp = [](const auto &a, const auto &b){return a.second >= b.second;};
        sort(sorted_frequency.begin(), sorted_frequency.end(), cmp);

        // output the result
        vector<int> top_k;
        for (auto &[key, value]: sorted_frequency) {
            top_k.push_back(key);
            if (top_k.size() == k) break;
        }

        return top_k;
    }
};

