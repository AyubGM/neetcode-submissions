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
    void reorderList(ListNode* head) {
        ListNode* right = head;
        ListNode* mid = head;

        while (right && right->next)
        {
            right = right->next->next;
            mid = mid->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = mid->next;
        mid->next = nullptr;
        while (curr)
        {
            ListNode* tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second; 
            second->next = temp1; 

            first = temp1;    
            second = temp2;  
        }

    }
};
