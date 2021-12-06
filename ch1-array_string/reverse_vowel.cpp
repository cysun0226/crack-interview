/**
* Leetcode 345
* https://leetcode.com/problems/reverse-vowels-of-a-string/
*/ 

#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    /* save all the found vowels */
    string reverseVowels(string s) {
        vector<pair<char, int>> vowels;

        // find the vowels
        set<char> v_set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (size_t i = 0; i < s.size(); i++) {
            if (v_set.find(s[i]) != v_set.end()) {
                vowels.push_back(make_pair(s[i], i));
            }
        }

        // reverse the order
        int end = vowels.size()-1;
        for (int i = 0; i < vowels.size()/2; i++) {
            int tmp = vowels[i].second;
            vowels[i].second = vowels[end-i].second;
            vowels[end-i].second = tmp;
        }

        // fill the reversed vowels
        for (auto p : vowels) {
            s[p.second] = p.first;
        }
        
        return s;
    }

    /* reverse by double pointers */
    string reverseVowels_doublePointer(string s) {
        // find the vowels
        set<char> v_set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && v_set.find(s[left]) == v_set.end()) left++;
            while (left < right && v_set.find(s[right]) == v_set.end()) right--;
            
            // swap the value of two pointers
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;

            left++;
            right--;
        }
        
        return s;
    }
};
