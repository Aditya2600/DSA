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
    int findLen(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* findPrevious(ListNode* head) {
        ListNode* prev = head;
        while (prev->next->next != NULL) {
            prev = prev->next;
        }
        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        int len = findLen(head);
        k = k % len;
        while (k--) {
            ListNode* prev = findPrevious(head);
            ListNode* temp = prev->next;
            temp->next = head;
            prev->next = NULL;
            head = temp;
        }
        return head;
    }
};