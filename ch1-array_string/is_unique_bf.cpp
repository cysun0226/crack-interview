#include <string>
#include <iostream>

using namespace std;

// o2 brute force
// std::string isUnique(std::string s){
//   bool all_distinct = true;
//   int s_length = s.length();
  
//   for (int out_idx = 0; out_idx < s_length; out_idx++) {
//     for (int in_idx = 0; in_idx < s_length; in_idx++) {
//         if (out_idx != in_idx && s[in_idx] == s[out_idx]) {
//           all_distinct = false;
//           break;
//         }
//     }
//     if (all_distinct == false) break;
//   }
  
//   if (all_distinct)
//     return "YES";
//   else
//     return "NO";
// }

string isUnique(string s){
  bool all_distinct = true;
  int s_length = s.length();
  
  for (int out_idx = 0; out_idx < s_length-1; out_idx++) {
    for (int in_idx = out_idx+1; in_idx < s_length; in_idx++) {
        if (s[in_idx] == s[out_idx]) {
          all_distinct = false;
          break;
        }
    }
    if (all_distinct == false) break;
  }
  
  if (all_distinct)
    return "YES";
  else
    return "NO";
}



int main() {
    std::string input = "qwertyuiopasdfghjklzxcvbnm";
    std::cout << isUnique(input) << std::endl;
}



