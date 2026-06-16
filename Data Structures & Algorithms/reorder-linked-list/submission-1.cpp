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
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while (curr)
        {
            ListNode* currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;  
        }

        ListNode* list1 = head;
        ListNode* list2 = prev;

        while (list2)
        {
            ListNode* list1Next = list1->next;
            ListNode* list2Next = list2->next;

            list1->next = list2;
            list2->next = list1Next;


            list1 = list1Next;
            list2 = list2Next;
        }
        

    }
};
