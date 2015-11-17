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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *l3 = NULL, **p3 = &l3;
        int quotient = 0, remaind = 0, sum = 0;
        int val1, val2;

        while( p1 != NULL || p2 != NULL || quotient != 0 ) {
            if(p1 != NULL){
                val1 = p1->val;
                p1 = p1->next;
            } 
            else
                val1 = 0;

            if(p2 != NULL){
                val2 = p2->val;
                p2 = p2->next;
            } 
            else
                val2 = 0;

            sum = val1 + val2 + quotient;
            remaind = sum % 10;
            quotient = sum / 10;

            ListNode *node = new ListNode(remaind);
            *p3 = node;
            p3 = &(node->next);
        }
        return l3;
    }
};
