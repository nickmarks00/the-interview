/*
 * REVERSE LINKED LIST
 * FROM: LeetCode
 * NUMBER: 206
 * DIFFICULTY: Easy
 * LANGUAGE: C++
 * Given the head of a singly linked list, reverse the list, and return the new
 * head.
 *
 */
#include <iostream>
#include <vector>

using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *curr = head;
        ListNode *adj;
        ListNode *nxt_adj;

        if (curr == nullptr || curr->next == nullptr) return curr;

        adj = curr->next;
        nxt_adj = adj->next;
        adj->next = curr;
        curr->next = nullptr;

        while (nxt_adj != nullptr) {  // we have at least three nodes
            curr = adj;
            adj = nxt_adj;
            nxt_adj = adj->next;
            adj->next = curr;
        }

        return adj;
    }
    ListNode *createLinkedList(vector<int> list) {
        if (list.size() == 0) return nullptr;
        ListNode *head = new ListNode(list[0]);
        ListNode *curr = head;
        for (int i = 1; i < list.size(); i++) {
            curr->next = new ListNode(list[i]);
            curr = curr->next;
        }
        return head;
    }
};

int main() {

    // Empty linked list
    Solution s;
    vector<vector<int>> v = {{}, {1, 2}, {1, 2, 3, 4, 5}};
    for (auto list : v) {
        cout << "Input: ";
        for (auto i : list) { cout << i << " "; }
        cout << "Output: ";
        ListNode *head = s.createLinkedList(list);
        ListNode *reversed = s.reverseList(head);
        while (reversed != nullptr) {
            cout << reversed->val << " ";
            reversed = reversed->next;
        }
        cout << endl;
    }

    return 0;
}
