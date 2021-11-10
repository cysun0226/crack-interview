/**
* Leetcode 48. Rotate Image
* https://leetcode.com/problems/rotate-image/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // void rotate(vector<vector<int>>& matrix) {
        
    // }
    void rorate_extra(vector<vector<int>>& matrix) {
        // allocate another 2D matrix and do the rotation
        vector<vector<int>> rotated;
        rotated.assign(matrix.begin(), matrix.end());
        for (size_t r = 0; r < matrix.size(); r++){
            for (size_t c = 0; c < matrix[0].size(); c++){
                // (r, c) -> (c, c.size()-1-r)
                rotated[c][matrix[0].size()-1 -r] = matrix[r][c];
            }
        }
        cout << "\nRotated: \n" << endl;
        print_matrix(rotated);
    }

    void print_matrix(vector<vector<int>>& matrix) {
        for (size_t r = 0; r < matrix.size(); r++){
            for (size_t c = 0; c < matrix[0].size(); c++){
                cout << matrix[r][c] << "\t";
            }
            cout << endl;
        }   
    }
};

int main(){
    vector<vector<int>> mat{
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };

    Solution().print_matrix(mat);
    Solution().rorate_extra(mat);

    return 0;
}