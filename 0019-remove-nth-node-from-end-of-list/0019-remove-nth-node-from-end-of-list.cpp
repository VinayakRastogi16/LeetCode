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

    int getSize(ListNode* head){
        ListNode* temp = head;
        int size = 0;
         
        while(temp != NULL){
            temp = temp->next;
            size++;
        }

        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = getSize(head);
        ListNode* prev = head;

        if (m == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        for(int i = 1; i < (m-n); i++){
            prev = prev->next;

        }

        ListNode* todel = prev->next;
        prev->next = todel->next;

        delete todel;
        return head;
    }
};