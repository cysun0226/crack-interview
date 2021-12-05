#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> sequences;
        for (size_t i = 0; i < nums.size(); i++) {
            vector<int> increase_seq = {nums[i]};
            for (size_t j = i+1; j < nums.size(); j++) {
                int end = increase_seq.size()-1 ;
                if (nums[j] > increase_seq.back()) {
                    increase_seq.push_back(nums[j]);
                }
                else if (nums[j] > increase_seq[end-1]) {
                    increase_seq.pop_back();
                    increase_seq.push_back(nums[j]);
                }
            }
            sequences.push_back(increase_seq);
        }

        // find the max length
        int max_length = 0;
        for (auto seq : sequences) {
            if (seq.size() > max_length)
                max_length = seq.size();
        }

        return max_length;
    }
};