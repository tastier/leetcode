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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        vector<ListNode*> v;
        int len = 0;
        //one pass
        while(p){
            ++len;
            v.push_back(p);
            p = p->next;
        }
        int num = len - n; // delete v[num]
        if(num == 0)
            return head->next;
        p = v[num - 1];
        p->next = p->next->next;
        return head;
    }
};
