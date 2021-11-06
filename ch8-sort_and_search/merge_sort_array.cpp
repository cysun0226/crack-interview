/**
* Leetcode 88. Merge Sorted Array
* https://leetcode.com/problems/merge-sorted-array/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.size() == 0)
            return;

        vector<int> merge_arr;
        int idx_1 = 0, idx_2 = 0;
        for (size_t i = 0; i < m+n; i++){
            if (idx_2 >= n){
                merge_arr.push_back(nums1[idx_1]);
                idx_1++;
                continue;
            }
            if (idx_1 >= m){
                merge_arr.push_back(nums2[idx_2]);
                idx_2++;
                continue;
            }

            if (nums1[idx_1] < nums2[idx_2]){
                merge_arr.push_back(nums1[idx_1]);
                idx_1++;
            }
            else{
                merge_arr.push_back(nums2[idx_2]);
                idx_2++;
            }
        }

        nums1 = merge_arr;
    }
};

int main(){
    // vector<int> n1{1,2,3,0,0,0}, n2{2,5,6};
    // int m = 3, n = 3;
    vector<int> n1{2,0}, n2{1};
    int m = 1, n = 1;
    Solution().merge(n1, m, n2, n);

    return 0;
}