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
    ListNode* partition(ListNode* head, int x) {
       ListNode* first = new ListNode(0) ;
       ListNode* second = new ListNode(0) ;
       
       ListNode *temp1 = first ,  *temp2 = second ;
        
        
       ListNode* curr = head ; 
        
        
       while(curr!=NULL){
           
           if(curr->val < x){
               first->next = curr ;
               first = first->next ;
           }else{
               second->next = curr ;
               second = second->next ;
           }
           
          curr = curr->next ; 
       } 
        
      second->next = NULL ;  
      first->next  = temp2->next ;
      return temp1->next ;  
        
        
    }
};