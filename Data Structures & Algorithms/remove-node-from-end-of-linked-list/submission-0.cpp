/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int size = 1;
        ListNode* tail = head;

        while (tail->next)
        {
            tail = tail->next;
            size++;
        }

        ListNode* nodeToDelete = head;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        for (int i = 0; i < size - n; i++)
        {
            prev = nodeToDelete;
            nodeToDelete = nodeToDelete->next;
        }

        prev->next = nodeToDelete->next;

        delete nodeToDelete;

        return dummy.next;
    }
};
