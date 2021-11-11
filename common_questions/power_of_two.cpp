/**
* Leetcode 231
* https://leetcode.com/problems/power-of-two/
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        
        int count = 0;
        while(n != 1) {
            if (n%2) count++;
            n = n/2;
        }
        
        return (count > 0)? false : true;
    }
};
