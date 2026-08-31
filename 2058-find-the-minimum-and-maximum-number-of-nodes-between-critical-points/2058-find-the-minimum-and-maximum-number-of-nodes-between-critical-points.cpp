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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> CP;
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        ListNode* prev = head;
        
        int i = 1;
        while(fast){

            if((slow->val>prev->val && slow->val>fast->val)||
            (slow->val<prev->val && slow->val<fast->val))CP.push_back(i);

            i++;

            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }


        if(CP.size()<2)return {-1,-1};

        int minDist = INT_MAX;

        for(int j = 1; j<CP.size();j++){
            minDist = min(minDist, CP[j]-CP[j-1]);
        }
        int maxDist = CP.back()-CP.front();

        return {minDist, maxDist};
    }
};