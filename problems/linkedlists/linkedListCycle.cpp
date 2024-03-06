/*
* LINKED LIST CYCLE
* FROM: LeetCode
* NUMBER: 141
* DIFFICULTY: Easy
* LANGUAGE: C++
* Given head, the head of a linked list, determine if the linked list has a
cycle in it.

There is a cycle in a linked list if there is some node in the list that can be
reached again by continuously following the next pointer. Internally, pos is
used to denote the index of the node that tail's next pointer is connected to.
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) { return true; }
        }
        return false;
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

    ListNode *returnTail(ListNode *head) {
        ListNode *curr = head;
        while (curr->next) { curr = curr->next; }
        return curr;
    }
};

int main() {

    Solution s;
    vector<vector<int>> nodeLists{{3, 2, 0, -4}, {1, 2}, {1}};
    vector<int> positions{1, 0, -1};
    vector<bool> results = {true, true, false};

    for (int i = 0; i < nodeLists.size(); i++) {
        ListNode *head = s.createLinkedList(nodeLists[i]);
        if (positions[i] != -1) {  // create cycle
            ListNode *tail = s.returnTail(head);
            ListNode *curr = head;
            for (int j = 0; j < positions[i]; j++) { curr = curr->next; }
            tail->next = curr;
        }
        bool res = s.hasCycle(head);
        try {
            if (res != results[i]) {
                throw invalid_argument("FAILED TEST CASE");
            }
        } catch (const invalid_argument &e) {
            cout << "Test case " << i << "failed. Got: " << res
                 << " Expected: " << results[i] << endl;
        }
    }
}
