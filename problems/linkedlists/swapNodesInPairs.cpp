/*
 * SWAP NODES IN PAIRS
 * FROM: LeetCode
 * NUMBER: 24
 * DIFFICULTY: Medium
 * LANGUAGE: C++
 * Given a linked list, swap every two adjacent nodes and return its head. You
 * must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *curr = head;
        ListNode *nxt;
        ListNode *prev;
        if (curr == nullptr) { return head; }
        if (curr->next != nullptr) {
            nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = curr;
            head = nxt;
            prev = curr;
            curr = curr->next;
        }
        while (curr != nullptr) {
            if (curr->next == nullptr) { return head; }
            nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = curr;
            prev->next = nxt;
            prev = curr;
            curr = curr->next;
        }

        return head;
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

    Solution s;

    vector<vector<int>> inputs{{1, 2, 3, 4}, {}, {1}, {1, 2, 3, 4, 5}};
    vector<vector<int>> outputs{{2, 1, 4, 3}, {}, {1}, {2, 1, 4, 3, 5}};

    for (int i = 0; i < inputs.size(); i++) {
        ListNode *llistIn = s.createLinkedList(inputs[i]);
        ListNode *swapped = s.swapPairs(llistIn);

        bool res = true;
        int j = 0;
        ListNode *curr = swapped;
        while (curr != nullptr) {
            if (curr->val != outputs[i][j]) {
                res = false;
                break;
            } else {
                j++;
                curr = curr->next;
            }
        }
        cout << "Swapped linked list passed? " << res << endl;
    }

    return 0;
}
