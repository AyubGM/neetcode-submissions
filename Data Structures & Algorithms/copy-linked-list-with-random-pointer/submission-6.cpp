/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {

        if (!head) return nullptr;
        
        Node* curr = head;

        while (curr)
        {
            Node* currPrime = new Node(curr->val);
            Node* temp = curr->next;
            curr->next = currPrime;
            currPrime->next = temp;
            curr = curr->next->next;
        }

        curr = head;

        while (curr)
        {
            curr->next->random = curr->random ? curr->random->next : nullptr;
            curr = curr->next->next;
        }

         
        curr = head;
        Node* newHead = curr->next;

        while (curr)
        {
            Node* clone = curr->next;
            curr->next = clone->next;
            curr = curr->next;

            if (curr) {
                clone->next = curr->next;     
            }
            
        }

        return newHead;
    }
};
