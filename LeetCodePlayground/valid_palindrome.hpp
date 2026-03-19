// https://leetcode.com/problems/valid-palindrome

#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    std::string str;
    str.reserve(s.size());
    for (size_t i = 0; i < s.size(); i++) {
      if (isalnum(s[i])) {
        str += std::tolower(static_cast<unsigned char>(s[i]));
      }
    }
    size_t left  = 0;
    size_t right = str.size() - 1;
    while (left < right) {
      if (str[left] != str[right]) {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }
};
