/*
* PALINDROMES
* FROM : LeetCode
* NUMBER: 9
* DIFFICULTY: Easy
* LANGUAGE: C++
* Description:
  Given an integer x, return true if x is palindrome integer.
  An integer is a palindrome when it reads the same backward as forward.
  For example, 121 is palindrome while 123 is not.
*/

#include <iostream>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {

    if (x < 0) {
      return false;
    }
    long reverse = 0;
    int temp = x;
    while (temp != 0) {
      int remainder = temp % 10;
      reverse = reverse * 10 + remainder;
      temp /= 10;
    }
    return reverse == x;
  }
};

int main() {
  Solution solution;
  int x = 121;
  cout << "Integer " << x << " is a palindrome? " << solution.isPalindrome(x)
       << endl;
  int y = 2244;
  cout << "Integer " << y << " is a palindrome? " << solution.isPalindrome(y)
       << endl;
  int z = 123454321;
  cout << "Integer " << z << " is a palindrome? " << solution.isPalindrome(z)
       << endl;
  return 0;
}
