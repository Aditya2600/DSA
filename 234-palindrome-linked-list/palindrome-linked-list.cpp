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
    // ListNode* reverse(ListNode* head){
    //     if(head == NULL || head -> next == NULL){
    //         return head;
    //     }
    //     ListNode* newHead = reverse(head -> next);
    //     ListNode* front = head -> next;
    //     front -> next = head;
    //     head -> next = NULL;
    //     return newHead;
    // }
    // bool isPalindrome(ListNode* head) {
    //     ListNode* newHead = reverse(head);
    //     return (newHead == head) ? true : false;
    // }

//     bool isPalindrome(ListNode* head) {
//         ListNode* temp = head;
//         stack<int> st;
//         while(temp != NULL){
//             st.push(temp->val);
//             temp = temp -> next;
//         }
//         temp = head;
//         while(temp != NULL){
//             if(temp->val != st.top()){
//                 return false;
//             }
//             temp = temp -> next;
//             st.pop();
//         }
//         return true;
//     }
// };
// class Solution {
// public:
//  bool isPalindrome(ListNode* head) {
//         ListNode* temp = head;
//         stack<int> st;
//         while(temp != NULL){
//             st.push(temp->val);
//             temp = temp -> next;
//         }
//         temp = head;
//         while(temp != NULL){
//             if(temp->val != st.top()){
//                 return false;
//             }
//             temp = temp -> next;
//             st.pop();
//         }
//         return true;
//     }
// };

class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            head = head -> next;
            temp -> next = prev;
            prev = temp;
            temp = head;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;
        while(f -> next != NULL && f -> next -> next != NULL){
            s = s -> next;
            f = f -> next -> next;
        }
        ListNode* newHead = reverse(s -> next);
        f = head;
        s = newHead;
        while(s != NULL && f != NULL){
            if(s -> val == f -> val){
                s = s -> next;
                f = f -> next;
            }
            else return false;
        }
        reverse(newHead);
        return true;
    }
};