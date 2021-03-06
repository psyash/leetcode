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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

      if(l1==NULL){
        return l2;
      }
      else if(l2==NULL){
        return l1;
      }
      ListNode* c;

      if(l1->data <= l2->data){
        c = l1;
        c->next = mergeTwoLists(l1->next, l2);
      }
      else{
        c = l2;
        c->next = mergeTwoLists(l1, l2->next);
      }
        return c;
    }
};