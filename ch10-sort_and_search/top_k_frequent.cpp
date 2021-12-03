/**
* Leetcode 347
* https://leetcode.com/problems/top-k-frequent-elements/
*/

#include <vector>
#include <map>
using namespace std;

class Solution {
// private:
    // typedef map<int, int> F_MAP;

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;

        for (int i : nums) {
            if (frequency.find(i) == frequency.end())
                frequency[i] = 1;
            else
                frequency[i]++;
        }

        // sort by the counted value
        map<int, int> sorted_frequency;
        for (auto const &[key, value] : frequency) {
            sorted_frequency.emplace(value, key);
        }

        // output the result
        vector<int> top_k;
        auto iter = sorted_frequency.rbegin();
        for (int i = 0; i < k; i++) {
            top_k.push_back(iter->second);
            ++iter;
        }

        return top_k;
    }
};

