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
    ListNode* findkNode(ListNode* head, int k){
        while(head && --k){
            head = head -> next;
        }
        return head;
    }

    ListNode* reverse(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* newHead = reverse(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = temp;
        while(temp != NULL){
            ListNode* kNode = findkNode(temp, k);
            if(kNode == NULL){
                if(prev){
                    prev -> next = temp;
                    break;
                }
            }
            ListNode* nextNode = kNode -> next;
            kNode -> next = NULL;
            reverse(temp);
            if(temp == head){
                head = kNode;
            }
            else{
                prev -> next = kNode;               
            }
            prev = temp;
            temp = nextNode;
        }        
        return head;
    }
};