/*
* Leetcode 1518
* https://leetcode.com/problems/water-bottles/
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0, full = numBottles, drunk = 0;
        while (full > 0) {
            // drink
            drunk += full;
            empty += full;
            full = 0;
            // exchange
            full = empty / numExchange;
            empty = empty % numExchange;
        }
        
        return drunk;
    }
};

int main() {
    cout << Solution().numWaterBottles(9, 3) << endl;

    return 0;
}
