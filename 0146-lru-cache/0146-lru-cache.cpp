class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> mp;

    void deleteNode(node* delNode) {
        node* prevNode = delNode->prev;
        node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertAfterHead(node* newNode) {
        node* currAfterHead = head->next;
        head->next = newNode;
        newNode->next = currAfterHead;
        newNode->prev = head;
        currAfterHead->prev = newNode;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            node* Node = mp[key];
            deleteNode(Node);
            insertAfterHead(Node);
            return Node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            node* Node = mp[key];
            Node->val = value;
            deleteNode(Node);
            insertAfterHead(Node);
        } else {
            if (mp.size() == cap) {
                node* Node = tail->prev;
                mp.erase(Node->key);
                deleteNode(Node);
            }
            node* Node = new node(key, value);
            mp[key] = Node;
            insertAfterHead(Node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */