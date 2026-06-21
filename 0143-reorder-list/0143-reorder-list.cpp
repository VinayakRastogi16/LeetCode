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
    ListNode* splitAtMid(ListNode* head){
        ListNode* slow = head;
        ListNode* prev = NULL;
        ListNode* fast = head;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev != NULL){
            prev->next = NULL;
        }

        return slow;
    }
    

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    void zigZag(ListNode* head){
        ListNode* rightHead = splitAtMid(head);
        ListNode* revHead = reverse(rightHead); 


        ListNode* left = head;
        ListNode* right = revHead;


        while(left !=NULL && right !=NULL){
            ListNode* leftNext = left->next;
            ListNode* rightNext = right->next;

            left->next= right;

            if(leftNext == NULL){
                break;
            }

            right->next = leftNext;
            left = leftNext;
            right = rightNext;
        }

    }
        void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;

        zigZag(head);
}
};