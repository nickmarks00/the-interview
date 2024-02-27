/*
 * REMOVE NTH NODE FROM END OF LIST
 * FROM: LeetCode
 * NUMBER: 19
 * DIFFICULTY: Medium
 * LANGUAGE: C++
 * Given the head of a linked list, remove the nth node from the end of the list
 * and return its head.
 */

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *lPtr = head;
    ListNode *rPtr = head;
    ListNode *prev = head;

    for (int i = 0; i < n - 1; i++) {
      rPtr = rPtr->next;
    }
    while (rPtr->next != nullptr) {
      prev = lPtr;
      lPtr = lPtr->next;
      rPtr = rPtr->next;
    }
    prev->next = lPtr->next;

    if (head == rPtr) {
      return nullptr;
    } else if (head == lPtr) {
      return lPtr->next;
    }
    return head;
  }
};

int main() {
  Solution solution;
  ListNode *head = new ListNode(1);
  ListNode *second = new ListNode(2);
  ListNode *third = new ListNode(3);
  ListNode *fourth = new ListNode(4);
  ListNode *fifth = new ListNode(5);
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  ListNode *result = solution.removeNthFromEnd(head, 2);
  while (result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
  return 0;
}
