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
    ListNode* middleNode(ListNode* head) {
        if(!head) return NULL;
        int len = 0;
        for(ListNode* p = head; p; p = p->next){
            len++;
        }
        int step = len/2;
        ListNode* p = head;
        while(step--){
            p = p -> next;
        }
        return p;
    }
};