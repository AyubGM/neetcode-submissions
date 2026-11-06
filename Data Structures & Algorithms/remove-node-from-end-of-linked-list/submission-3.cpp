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
        ListNode* dummy = new ListNode(0, head);

        int count = 0;
        ListNode* curr = head;
        while (curr)
        {
            count++;
            curr = curr->next;
        }

        int index = count - n;

        curr = dummy;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }


        ListNode* toDel = curr->next;
        curr->next = toDel->next;

        delete toDel;
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead; 
    }
};
