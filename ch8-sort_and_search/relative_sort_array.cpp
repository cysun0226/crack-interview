/**
* Leetcode 1122
* https://leetcode.com/problems/relative-sort-array/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // the initial correct indices
        int idx_1 = 0;
        // sort in the arr2 order
        for (size_t idx_2 = 0; idx_2 < arr2.size(); idx_2++){
            // check if there is element is in the correct order
            for (size_t i = idx_1; i < arr1.size(); i++){
                if (arr1[i] == arr2[idx_2])
                    idx_1++;
                else
                    break;
            }

            for (size_t i = idx_1+1; i < arr1.size(); i++){
                // find the number of the current target
                if (arr1[i] == arr2[idx_2]){
                    // exchange with the front
                    int tmp = arr1[idx_1];
                    arr1[idx_1] = arr1[i];
                    arr1[i] = tmp;
                    idx_1++;
                }
            }
        }

        // sort the left elements
        for (size_t i = idx_1; i < arr1.size()-1; i++){
            for (size_t j = i+1; j < arr1.size(); j++){
                if (arr1[i] > arr1[j]){
                    int tmp = arr1[j];
                    arr1[j] = arr1[i];
                    arr1[i] = tmp;
                }
            }
        }

        return arr1;
    }
};

int main(){
    // vector<int> arr1{2,3,1,3,2,4,6,7,9,2,19}, arr2{2,1,4,3,9,6};
    vector<int> arr1{2,3,1,3,2,4,6,7,9,2,19,18,8,5,21,7}, arr2{2,1,4,3,9,6};
    Solution().relativeSortArray(arr1, arr2);

    // Output: [2,2,2,1,4,3,3,9,6,7,19]


    return 0;
}