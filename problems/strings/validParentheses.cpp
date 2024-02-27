/*
* VALID PARENTHESES
* FROM: LeetCode
* NUMBER: 9
* DIFFICULTY: Easy
* LANGUAGE: C++
* Description:
* Given a string s containing just the characters '(', ')', '{', '}', '[' and
']', determine if the input string is valid.

* An input string is valid if:
*   1. Open brackets must be closed by the same type of brackets.
*   2. Open brackets must be closed in the correct order.
*   3. Every close bracket has a corresponding open bracket of the same type.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
  int top;

public:
  Solution() { top = -1; }
  bool isValid(string s) {
    int n = s.length();
    char stack[n];
    top = -1;

    if (n % 2 != 0) {
      return false;
    } // we know immediately this is invalid

    for (auto &ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        push(stack, ch);
      } else if (top == -1) { // stack is empty
        return false;
      } else if (ch == ')' && stack[top] != '(') {
        return false;
      } else if (ch == ']' && stack[top] != '[') {
        return false;
      } else if (ch == '}' && stack[top] != '{') {
        return false;
      } else {
        pop(stack);
      }
    }
    return top == -1 ? true : false; // stack needs to be empty here!
  }

  void push(char stack[], char ch) { stack[++top] = ch; }

  char pop(char stack[]) { return stack[top--]; }
};

int main() {
  Solution solution;
  string s = "()";
  cout << "String " << s << " is valid? " << solution.isValid(s) << endl;
  string t = "()[]{}";
  cout << "String " << t << " is valid? " << solution.isValid(t) << endl;
  string u = "(]";
  cout << "String " << u << " is valid? " << solution.isValid(u) << endl;
  string v = "([)]";
  cout << "String " << v << " is valid? " << solution.isValid(v) << endl;
  string w = "{[]}";
  cout << "String " << w << " is valid? " << solution.isValid(w) << endl;
  return 0;
}

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st; // create an empty stack to store opening brackets
//         for (char c : s) { // loop through each character in the string
//             if (c == '(' || c == '{' || c == '[') { // if the character is an
//             opening bracket
//                 st.push(c); // push it onto the stack
//             } else { // if the character is a closing bracket
//                 if (st.empty() || // if the stack is empty or
//                     (c == ')' && st.top() != '(') || // the closing bracket
//                     doesn't match the corresponding opening bracket at the
//                     top of the stack (c == '}' && st.top() != '{') || (c ==
//                     ']' && st.top() != '[')) { return false; // the string is
//                     not valid, so return false
//                 }
//                 st.pop(); // otherwise, pop the opening bracket from the
//                 stack
//             }
//         }
//         return st.empty(); // if the stack is empty, all opening brackets
//         have been matched with their corresponding closing brackets,
//                            // so the string is valid, otherwise, there are
//                            unmatched opening brackets, so return false
//     }
// };
