/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node* temp = head;
//         unordered_map<Node*, Node*> mp;
//         while(temp != NULL){
//             Node* newNode = new Node(temp -> val);
//             mp[temp] = newNode;
//             temp = temp -> next;
//         }
//         temp = head;

//         while(temp != NULL){
//             Node* copyNode = mp[temp];
//             copyNode -> next = mp[temp -> next];
//             copyNode -> random = mp[temp -> random];
//             copyNode = copyNode -> next;
//             temp = temp -> next;
//         }
//         return mp[head];
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = new Node(temp -> val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp -> next -> next;
        }

        temp = head;
        while (temp != NULL) {
            Node* copyNode = temp -> next;
            if(temp -> random != NULL){
                copyNode -> random = temp -> random -> next;
            }
            else{
                copyNode -> random = NULL;
            }
            temp = copyNode -> next;
        }

        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while(temp != NULL){
            Node* copyNode = temp -> next;
            res -> next = copyNode;
            res = res -> next;
            temp -> next = copyNode -> next;
            temp = temp -> next;
        }
        return dummy -> next;
    }
};