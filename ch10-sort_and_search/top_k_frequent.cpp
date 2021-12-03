/**
* Leetcode 347
* https://leetcode.com/problems/top-k-frequent-elements/
*/

#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
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
        priority_queue<pair<int, int>> sort_freq;
        for (auto &[key, value] : frequency) {
            sort_freq.push({value, key});
        }

        // output the result
        vector<int> top_k;
        while (top_k.size() != k) {
            auto top = sort_freq.top();
            sort_freq.pop();
            top_k.push_back(top.second);
        }

        return top_k;
    }

    vector<int> topKFrequent_map(vector<int>& nums, int k) {
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

