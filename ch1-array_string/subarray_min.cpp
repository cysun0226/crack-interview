/*
* Leetcode 907
* https://leetcode.com/problems/sum-of-subarray-minimums/
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void printArray(vector<int>& arr) {
        cout << "arr: ";
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int sumSubarrayMins(vector<int>& arr) {
        auto min = [](vector<int>& a) {
            int min = INT_MAX;
            for (size_t i = 0; i < a.size(); i++) {
                if (a[i] <= min)
                    min = a[i];
            }
            return min;
        };

        // window size
        int sum = 0;
        for (int w = 1; w <= arr.size(); w++) {
            // each sub-array (start index)
            for (size_t i = 0; i < arr.size()+1-w; i++) {
                vector<int> subarr(&arr[i], &arr[i+w]);
                printArray(subarr);
                sum += min(subarr);
            }
        }

        return sum;
    }
};

int main() {
    vector<int> arr{3,1,2,4};
    Solution().sumSubarrayMins(arr);

    return 0;
}
