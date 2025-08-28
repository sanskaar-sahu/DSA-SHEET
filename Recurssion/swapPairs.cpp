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
    ListNode* swapPair(ListNode* head){
        if(!head || !head->next) return head;

        ListNode * first = head;
        ListNode * second = head->next;

        first->next = swapPair(second->next);

        second->next = first;

        return second;
    }
    
    ListNode* swapPairs(ListNode* head) {
            if (!head || !head->next) return head;

        ListNode *first = head;
        ListNode *sec = head->next;
        ListNode *prev = NULL;

        while (first && sec) {
            ListNode* third = sec->next;  // node after the pair

            // swap
            sec->next = first;
            first->next = third;

            // connect with previous swapped pair
            if (prev != NULL) {
                prev->next = sec;
            } else {
                head = sec;  // update head only for the first swap
            }

            // move pointers forward
            prev = first;
            first = third;
            if (first) sec = first->next;
            else sec = NULL;
        }

        return head;
    }
};