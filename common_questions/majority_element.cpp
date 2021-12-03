/**
* Leetcode 169. Majority Element
* https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        for (int n : nums) {
            if (count.find(n) == count.end())
                count[n] = 1;
            else
                count[n]++;
        }
        
        vector<pair<int, int>> sort_count;
        for(auto const &item : count) {
            sort_count.push_back(item);
        }
        
        auto cmp = [](const auto &a, const auto &b){return a.second >= b.second;};
        sort(sort_count.begin(), sort_count.end(), cmp);
        
        return sort_count[0].first;
    }
};