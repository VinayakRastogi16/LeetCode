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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* evenHead = curr;

        while(curr != NULL && curr->next != NULL){
            prev->next = curr->next;
            prev = prev->next;

            curr->next = prev->next;
            curr = curr->next;

        }

        prev->next = evenHead;

        return head;
    }
};