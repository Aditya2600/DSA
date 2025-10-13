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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* temp = head;
//         int len = 0;
//         while(temp != NULL){
//             temp = temp -> next;
//             len++;
//         }
//         if(len == n){
//             head = head -> next;
//             return head;
//         }
//         int m = len - n + 1;
//         ListNode* curr = head;
//         for(int i=0; i<m-2; i++){
//             curr = curr->next;
//         }
//         curr -> next = curr -> next -> next;
//         return head;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0; i<n; i++){
            fast = fast -> next;
        }
        if(fast == NULL) return head -> next;
        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};