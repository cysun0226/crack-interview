#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mag_count;

        for (char c : magazine) {
            if (mag_count.find(c) == mag_count.end())
                mag_count[c] = 1;
            else
                mag_count[c]++;
        }
        
        for (char c : ransomNote) {
            if (mag_count.find(c) == mag_count.end())
                return false;
            else {
                mag_count[c]--;
                if (mag_count < 0)
                    return false;
            }
                
        }

        return true;
    }
};