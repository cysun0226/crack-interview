#include <string>
#include <iostream>
#include <map>

using namespace std;

string checkPermutation(string a, string b){
  bool is_permutation = true;

  // create a dictionary to record elements of the input
  map<char, int> in_dict;
  for (size_t i = 0; i < a.size(); i++){
      // check if exist
      if (in_dict.find(a[i]) == in_dict.end()) { // not exist
          in_dict[a[i]] = 0;
      }
      else {
          in_dict[a[i]]++;
      }
  }

  // create a dictionary to record elements of the target
  map<char, int> tar_dict;
  for (size_t i = 0; i < b.size(); i++){
      // check if exist
      if (tar_dict.find(b[i]) == tar_dict.end()) { // not exist
          tar_dict[b[i]] = 0;
      }
      else {
          tar_dict[b[i]]++;
      }
  }

  // check if two dictionaries are the same
  auto iter_in = in_dict.begin();
  while (iter_in != in_dict.end()){
      // check if the key exists in the target dict
      auto iter_tar = tar_dict.find(iter_in->first);
      if (iter_tar == tar_dict.end()) { // not exist
          is_permutation = false;
          break;
      }
      else {
          if (iter_tar->second != iter_in->second) {
              is_permutation = false;
              break;
          }
      }
      
      ++iter_in;
  }

  // return the result
  if (is_permutation)
    return "YES";
  else
    return "NO";
}



int main() {
    std::string a = "abc";
    std::string b = "cab";
    std::cout << "Test case 1" << std::endl;
    std::cout << checkPermutation(a, b) << std::endl << std::endl;
    
    a = "car", b = "cer";
    std::cout << "Test case 2" << std::endl;
    std::cout << checkPermutation(a, b) << std::endl;

}



