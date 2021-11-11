/**
 * Leetcode 912. Sort an Array
 * https://leetcode.com/problems/sort-an-array/
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void printArray(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    /* quick sort */
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

    /* Merge sort */
    vector<int> merge(vector<int> arr_left, vector<int> arr_right) {
        if (arr_left.size() == 0)
            return arr_right;
        if (arr_right.size() == 0)
            return arr_left;

        // merge & sort
        vector<int> merged;
        int left_idx = 0, right_idx = 0, total = arr_left.size()+arr_right.size();

        for (size_t i = 0; i < total; i++){
            if (left_idx == -1) {
                merged.push_back(arr_right[right_idx]);
                right_idx++;
            }
            else if (right_idx == -1) {
                merged.push_back(arr_left[left_idx]);
                left_idx++;
                
            }

            else if (left_idx != -1 && arr_left[left_idx] <= arr_right[right_idx]) {
                merged.push_back(arr_left[left_idx]);
                left_idx++;
                if (left_idx == arr_left.size())
                    left_idx = -1; // all the elements are merged
                
            }
            else if (right_idx != -1 && arr_right[right_idx] < arr_left[left_idx]) {
                merged.push_back(arr_right[right_idx]);
                right_idx++;
                if (right_idx == arr_right.size())
                    right_idx = -1; // all the elements are merged
            }
        }
        
        return merged;
    }

    vector<int> mergeSort(vector<int> nums) {
        int n = nums.size();

        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                int tmp = nums[0];
                nums[0] = nums[1];
                nums[1] = tmp;
            }
            return nums;
        }

        if (nums.size() <= 1) {
            return nums;
        }

        vector<int> arr_left(&nums[0], &nums[n/2]);
        vector<int> arr_right(&nums[(n/2)], &nums[n]);

        arr_left = mergeSort(arr_left);
        arr_right = mergeSort(arr_right);

        return merge(arr_left, arr_right);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> result = mergeSort(nums);

        // quickSort(nums, 0, nums.size()-1);
        return result;
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
};

int main() {
    // std::vector<int> input{2, 6, 5, 3, 8, 7, 1, 0};
    std::vector<int> input{5, 1, 1, 2, 0, 0};
    std::vector<int> result = Solution().sortArray(input);
    Solution().printArray(result);

    return 0;
}