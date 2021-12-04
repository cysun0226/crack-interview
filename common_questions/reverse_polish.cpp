/**
* Leetcode 150
* https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;

        // get the top two stack values
        auto get_values = [&stack](){ 
            int v2 = stack.back();
            stack.pop_back();
            int v1 = stack.back();
            stack.pop_back();
            return make_pair(v1, v2);
        };

        for (string s : tokens) {
            int v1, v2;
            switch (s[0]) {
                // arithmetic operations
                case '+':
                    tie(v1, v2) = get_values();
                    stack.push_back(v1+v2);
                    break;
                case '-':
                    tie(v1, v2) = get_values();
                    stack.push_back(v1-v2);
                    break;
                case '*':
                    tie(v1, v2) = get_values();
                    stack.push_back(v1*v2);
                    break;
                case '/':
                    tie(v1, v2) = get_values();
                    stack.push_back(v1/v2);
                    break;
                
                // convert the string to integers
                default:
                    stack.push_back(stoi(s));
                    break;
            }
        }

        return stack.back();
    }
};

int main() {
    vector<string> test = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution().evalRPN(test);

    return 0;
}