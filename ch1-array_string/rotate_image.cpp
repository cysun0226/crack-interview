/**
* Leetcode 48. Rotate Image
* https://leetcode.com/problems/rotate-image/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int max_idx = matrix.size() - 1;
        for (size_t idt = 0; idt < matrix.size()/2; idt++){
            
            // shift 1 block (counter-clock) * needed times
            for (size_t s = 0; s < (matrix.size()-1)-idt*2; s++) {
                // boundaries
                int top = idt, btm = max_idx - idt, right = max_idx - idt, left = idt;
                int start_point = matrix[idt][idt];

                // left
                for (size_t r = top; r < btm; r++)
                    matrix[r][left] = matrix[r+1][left];
                // bottom
                for (size_t c = left; c < right; c++)
                    matrix[btm][c] = matrix[btm][c+1];
                // right
                for (size_t r = btm; r > top; r--)
                    matrix[r][right] = matrix[r-1][right];
                // top
                for (size_t c = right; c > left; c--)
                    matrix[top][c] = matrix[top][c-1];
                
                // fill the starting point
                matrix[idt][idt+1] = start_point;

                // cout << "round " << idt << endl;
                // print_matrix(matrix);    
            }
        }
    }


    void rotate_extra(vector<vector<int>>& matrix) {
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
        cout << endl;
    }
};

int main(){
    vector<vector<int>> mat{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        // {5, 1, 9, 11},
        // {2, 4, 8, 10},
        // {13, 3, 6, 7},
        // {15, 14, 12, 16}
    };

    Solution().print_matrix(mat);
    Solution().rotate(mat);
    Solution().print_matrix(mat);

    return 0;
}