/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else if(l1 == NULL && l2 != NULL)
            return l2;
        else if(l1 != NULL && l2 == NULL)
            return l1;
        ListNode *head;
        // ListNode *p1 = l1;
        // ListNode *p2 = l2;
        if(l1->val > l2->val){
            head = l2;
            l2 = l2->next;
        }
        else{ 
            head = l1;
            l1 = l1->next;
        }
        ListNode *p3 = head;
        while(l1 != NULL && l2 != NULL){
            if( l1->val > l2->val){
                p3->next = l2;
                l2 = l2->next;
            }
            else{
                p3->next = l1;
                l1 = l1->next;
            }
            p3 = p3->next;
        }
        // if(l1 == NULL && l2 != NULL)
        //     p3->next = l2;
        // else if(l1 != NULL && l2 == NULL)
        //     p3->next = l1;
        p3->next = l1 == NULL ? l2 : l1;
        return head;
    }
};
