#include <iostream>
#include <string>
#include <vector>

using namespace std;

string urlify(int n, string s){
    std::vector<string> tokens;
    int start_idx = 0, end_idx = 0;

    // seperate space and each word (tokenize the string), and insert %20 as the space
    for (int i = 0; i < n; i++){
        end_idx++;
        if (s[i] == ' ' || i == n-1) {
            int cut_idx = (s[i] == ' ') ? end_idx-start_idx-1 : end_idx-start_idx; // -1: remove the space
            string token = s.substr(start_idx, cut_idx);
            start_idx = end_idx;
            tokens.push_back(token);

            if (s[i] == ' ')
                tokens.push_back("%20");
        }
    }

    // concatenate the tokens to a string
    string result = "";
    for (int i = 0; i < tokens.size(); i++){
        result.append(tokens[i]);
    }

    return result;
}


int main() {
    std::string a = "the red fox";
    int an = 11;

    std::string b = "add spaces";
    int bn = 10;

    std::cout << "Test case 1" << std::endl;
    std::cout << urlify(an, a) << std::endl << std::endl;
    
    std::cout << "Test case 2" << std::endl;
    std::cout << urlify(bn, b) << std::endl;
}