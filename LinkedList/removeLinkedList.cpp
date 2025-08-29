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
    ListNode* removeElements(ListNode* head, int val) {

      //What if multiple nodes with val are at the beginning
        while(head && head->val == val){
            ListNode * temp = head ;
            head = head->next;
            delete temp;
        }

        // Step 2: Normal traversal
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* front = curr->next;

            if (curr->val == val) {
                prev->next = front;   // unlink node
                delete curr;          // free memory
                curr = front;         // move forward
            } else {
                prev = curr;          // shift prev
                curr = front;         // shift curr
            }
        }
        return head;
    }
};