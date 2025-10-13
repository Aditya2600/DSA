/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if (!headA || !headB) return nullptr;

//         ListNode* a = headA;
//         ListNode* b = headB;

//         // After at most 2 passes, either meet at intersection or both hit nullptr
//         while (a != b) {
//             a = a ? a->next : headB;
//             b = b ? b->next : headA;
//         }
//         return a; // either intersection node or nullptr
//     }
// };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headA;
        unordered_map<ListNode*, int> mp;
        while(temp != NULL){
            mp[temp] = 1;
            temp = temp -> next;
        }
        temp = headB;
        while(temp != NULL){
            if(mp.find(temp) != mp.end()){
                return temp;
            }
            temp = temp -> next;
        }
        return NULL;
    }
};