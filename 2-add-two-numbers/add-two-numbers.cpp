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
    // ListNode* numberToListReverse(long long n) {
    //     if (n == 0)
    //         return new ListNode(0);
    //     ListNode dummy(0), *tail = &dummy;
    //     while (n > 0) {
    //         tail->next = new ListNode(int(n % 10));
    //         tail = tail->next;
    //         n /= 10;
    //     }
    //     return dummy.next;
    // }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         long long num1 = 0;
//         long long num2 = 0;
//         ListNode* t1 = l1;
//         ListNode* t2 = l2;
//         long long x = 1;
//         while (t1 != NULL) {
//             num1 = num1 + (t1->val * x);
//             t1 = t1->next;
//             x *= 10;
//         }
//         x = 1;
//         for (ListNode* p = t2; p; p = p->next) {
//             num2 += p->val * x;
//             x *= 10;
//         }
//         long long sum = num1 + num2;        
//         return numberToListReverse(sum);
//     }
// };

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(l1 != NULL || l2 != NULL || carry == 1){
            int sum = 0;
            if(l1 != NULL){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += carry;
            carry = sum / 10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
        }
        return dummy -> next;
    }
};