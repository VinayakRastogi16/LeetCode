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

    ListNode* getKthNode(ListNode* temp, int k ){
        k-= 1;
        while(temp !=NULL && k>0){
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* findKNode(ListNode* temp, int k ){
        ListNode* kp = temp;
        for(int i = 0; i<k; i++){
            kp = kp->next;
        }



        return kp;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr =head;
        ListNode* prev = NULL;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        ListNode* nextNode;
        ListNode* prev = NULL;
        ListNode* newNode;        
        while(temp!=NULL){
            ListNode* kth = getKthNode(temp, k);
            if(kth ==NULL){
                if(prev)prev->next = temp;
                break;
            }

            nextNode = kth->next;
            kth->next = NULL;
            reverse(temp);

            if(temp ==head){
                head = kth;

            }else{
                prev->next = kth;
            }
            prev = temp;
            temp = nextNode;
        }

        return head;
        
    }
};