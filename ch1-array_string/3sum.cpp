/**
* Leetcode 15. 3 sum
* https://leetcode.com/problems/3sum/
*/

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum_bf(vector<int>& nums) {
        if (nums.size() < 3)
            return vector<vector<int>>();
        
        auto swap = [](int& a, int& b) {
            int tmp = a;
            a = b;
            b = tmp;
        };
        
        vector<vector<int>> result;
        map<vector<int>, bool> exist;
        
        // int i = 0, j = 1, k = 2;
        for (int i = 0; i < nums.size()-2; i++) {
            for (int j = i+1; j < nums.size()-1; j++) {
                for (int k = j+1; k < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        int idx1 = i, idx2 = j, idx3 = k;
                        // sort three nums
                        if (nums[idx1] > nums[idx2])
                            swap(idx1, idx2);
                        if (nums[idx1] > nums[idx3])
                            swap(idx1, idx3);
                        if (nums[idx2] > nums[idx3])
                            swap(idx2, idx3);
                        
                        vector<int> sol = {nums[idx1], nums[idx2], nums[idx3]};
                        exist[sol] = true;
                    }
                }
            }
        }
        
        auto iter = exist.begin();
        while(iter != exist.end()) {
            result.push_back(iter->first);
            ++iter;
        }
        
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());

        // double pointer
        vector<vector<int>> result;
        map<vector<int>, bool> exist;
        int prev_mid = INT32_MAX;
        for (size_t i = 1; i < nums.size(); i++) {
            int left = 0, right = nums.size()-1;
            vector<int> prev_sol;
            while (left < i && right > i) {
                int sum = nums[left]+nums[i]+nums[right];
                if (sum == 0) {
                    vector<int> sol{nums[left], nums[i], nums[right]};
                    exist[sol] = true;
                    left++;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        
        for (auto iter = exist.begin(); iter != exist.end(); iter++) {
            result.push_back(iter->first);
        }

        return result;
    }

    void printArray(vector<int> const &nums) {
        cout << "[nums] ";
        for (int n : nums) cout << n << " ";
        cout << endl;
    }
};


int main() {
    vector<int> data = {-1,0,1,2,-1,-4};
    Solution().threeSum(data);

    return 0;
}