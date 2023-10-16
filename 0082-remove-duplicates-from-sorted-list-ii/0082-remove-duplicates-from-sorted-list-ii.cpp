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
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode* dummy = new ListNode(0);
       dummy->next = head;
       ListNode* prev = dummy;
       ListNode* temp = head;
       while(temp != NULL && temp -> next != NULL){
           if(temp->val == temp->next->val){
               int n = temp->val;
               while(temp != NULL && temp->val == n){
                   temp = temp->next;
               }
               prev->next = temp;
           }
           else{
               prev = temp;
               temp = temp->next;
           }
       } 

       return dummy->next;
        
    }
};