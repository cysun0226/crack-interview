#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> rn_count, mag_count;

        for (char c : ransomNote) {
            if (rn_count.find(c) == rn_count.end())
                rn_count[c] = 1;
            else
                rn_count[c]++;
        }

        for (char c : magazine) {
            if (mag_count.find(c) == mag_count.end())
                mag_count[c] = 1;
            else
                mag_count[c]++;
        }

        // compare two maps
        for (auto iter = rn_count.begin(); iter != rn_count.end(); iter++) {
            int rn = iter->second;
            int mag = mag_count[iter->first];
            if (rn > mag)
                return false;
        }
        return true;
    }
};