class Solution {
public:
    Node* copyRandomList(Node* head) {
      //inserting the odes inbetween
      Node* temp = head;
      Node* cpyNode;
      while(temp!=NULL){
        cpyNode = new Node(temp->val);
        cpyNode->next = temp->next;
        temp->next = cpyNode;
        temp = temp->next->next;
      }


      //connect Random ptr

      temp = head;
      while(temp!=NULL){
        cpyNode = temp->next;
        if(temp->random!=NULL) {
            cpyNode->random = temp->random->next;
        }else{
            cpyNode->random = NULL;
        }

        temp = temp->next->next;
      }

      // Connect Next Pointer
        Node* dNode = new Node(-1);
        Node* res = dNode;
        temp = head;

        while(temp!=NULL){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dNode->next;

    }
};