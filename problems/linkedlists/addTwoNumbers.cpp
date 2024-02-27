/*
* ADD TWO NUMBERS
* FROM: LeetCode
* NUMBER: 2
* DIFFICULTY: Medium
* LANGUAGE: C++
* Description: You are given two non-empty linked lists representing two
non-negative integers. The digits are stored in reverse order, and each of their
nodes contains a single digit. Add the two numbers and return the sum as a
linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.
*/

// Definition for singly-linked list.
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    int sum;
    ListNode *head = new ListNode();
    ListNode *curr = head;
    while (l1 != nullptr && l2 != nullptr) {
      sum = l1->val + l2->val + carry;
      curr->val = sum % 10;
      carry = sum / 10;
      if (l1->next != nullptr && l2->next != nullptr) {
        ListNode *nxt = new ListNode();
        curr->next = nxt;
        curr = nxt;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    if (l1 != nullptr || l2 != nullptr) {
      ListNode *remainder = (l1 == nullptr) ? l2 : l1;
      while (remainder != nullptr) {
        ListNode *nxt = new ListNode();
        sum = carry + remainder->val;
        nxt->val = sum % 10;
        carry = sum / 10;
        curr->next = nxt;
        curr = nxt;
        remainder = remainder->next;
      }
    }
    if (carry == 1) {
      ListNode *leadingZero = new ListNode(1);
      curr->next = leadingZero;
    }
    return head;
  }
};

int main() {
  ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  Solution sol;
  ListNode *result = sol.addTwoNumbers(l1, l2);
  while (result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
  return 0;
}
