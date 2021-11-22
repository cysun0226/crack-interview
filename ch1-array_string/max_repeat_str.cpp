/**
* Leetcode 1668.
* https://leetcode.com/problems/maximum-repeating-substring/ 
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int max_repeat = 0, repeat = 0;
        for (size_t i = 0; i + word.size() <= sequence.size(); i++) {
            int rep_idx = 0;
            repeat = 0; 
            while (i + rep_idx + word.size() <= sequence.size()) {
                string substr = sequence.substr(i+rep_idx, word.size());
                if (substr == word) {
                    repeat++;
                    rep_idx += word.size();
                }
                else {
                    break;
                }
            }
            max_repeat = (repeat > max_repeat)? repeat : max_repeat;
        }
        
        return max_repeat;
    }
};


int main() {
    // string seq = "ababc", word = "ab";
    // string seq = "ababc", word = "ba";
    string seq = "aa", word = "a";

    cout << Solution().maxRepeating(seq, word) << endl;

    return 0;
}