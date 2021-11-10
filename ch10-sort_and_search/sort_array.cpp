/**
 * Leetcode 912. Sort an Array
 * https://leetcode.com/problems/sort-an-array/
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<int> bubbleSort(vector<int>& nums) {
        for (size_t i = 0; i < nums.size()-1; i++) {
            for (size_t j = i+1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    int tmp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = tmp;
                }
            }
        }
        return nums;
    }

    void printArray(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    std::vector<int> input{2, 6, 5, 3, 8, 7, 1, 0};
    Solution().bubbleSort(input);
    Solution().printArray(input);

    return 0;
}