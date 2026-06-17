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

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL){
            prev->next = NULL;
        }

        return slow;
    }

    bool isPalindrome(ListNode* head) {
        
        ListNode* rightHead = findMid(head);
        ListNode* rh = reverse(rightHead);
        ListNode* left = head;

        while(left && rh){
            if(left->val != rh->val){
                return false;
            }
            left = left->next;
            rh = rh->next;
        }


        return true;
        
    }
};