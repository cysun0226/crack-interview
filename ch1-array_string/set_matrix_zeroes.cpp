/*
* Leetcode 73. Set Matrix Zeroes
* https://leetcode.com/problems/set-matrix-zeroes/
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int, bool> column_set;
        map<int, bool> row_set;

        auto set_row = [&matrix](int r) {
            for (size_t c = 0; c < matrix[r].size(); c++)
                matrix[r][c] = 0;
        };

        auto set_column = [&column_set, &matrix](int c) {
            for (size_t r = 0; r < matrix.size(); r++)
                matrix[r][c] = 0;
        };

        for (size_t r = 0; r < matrix.size(); r++){
            for (size_t c = 0; c < matrix[r].size(); c++){
                // if found zero
                if (matrix[r][c] == 0) {
                    row_set[r] = true;
                    column_set[c] = true;
                }
            }
        }

        // set the marked column / row to 0
        auto iter = column_set.begin();
        while (iter != column_set.end()) {
            set_column(iter->first);
            ++iter;
        }

        iter = row_set.begin();
        while (iter != row_set.end()) {
            set_row(iter->first);
            ++iter;
        }
    }
};