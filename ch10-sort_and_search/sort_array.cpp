/**
 * Leetcode 912. Sort an Array
 * https://leetcode.com/problems/sort-an-array/
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int front, int end) {
        int tmp = nums[front];
        nums[front] = nums[end];
        nums[end] = tmp;
    }

    int partition(vector<int>& nums, int front, int end) {
        int pivot = nums[end];
        int idx_front = front-1;
        for (size_t idx_end = front; idx_end < end; idx_end++){
            if (nums[idx_end] <= pivot) {
                idx_front++;
                swap(nums, idx_front, idx_end);
            }
        }
        idx_front++;
        swap(nums, idx_front, end);
        
        return idx_front;
    }

    void quickSort(vector<int>& nums, int front, int end) {
        if (front < end) {
            int pivot = partition(nums, front, end);
            quickSort(nums, front, pivot-1);
            quickSort(nums, pivot+1, end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

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
    // std::vector<int> input{5, 1, 1, 2, 0, 0};
    Solution().sortArray(input);
    Solution().printArray(input);

    return 0;
}