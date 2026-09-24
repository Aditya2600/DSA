class LRUCache {
public:
    struct node{
        int key, val;
        node* prev;
        node* next;
        node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> mp;
    void deleteAtEnd(node* delNode){
       node* prevNode = delNode->prev;
       node* nextNode = delNode->next;

       prevNode->next = nextNode;
       nextNode->prev = prevNode;
    }

    void insertAtStart(node* newNode){
        node* currentAfterHead = head->next;
        newNode->prev = head;
        newNode->next = currentAfterHead;
        currentAfterHead->prev = newNode;
        head->next = newNode;

    }
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* Node = mp[key];
            deleteAtEnd(Node);
            insertAtStart(Node);
            return Node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* Node = mp[key];
            Node->val = value;
            deleteAtEnd(Node);
            insertAtStart(Node);
        }
        else{
            if(mp.size() == cap){
                node* Node = tail->prev;
                deleteAtEnd(Node);
                mp.erase(Node->key);
                
            }
            node* Node = new node(key, value);
            mp[key] = Node;
            insertAtStart(Node);          
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */