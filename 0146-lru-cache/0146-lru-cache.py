class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:

    def deleteNode(self, delNode):
        prevNode = delNode.prev
        nextNode = delNode.next
        prevNode.next = nextNode
        nextNode.prev = prevNode

    def insertAtStart(self, addNode):
        addNode.next = self.head.next
        addNode.prev = self.head

        self.head.next.prev = addNode
        self.head.next = addNode

    def __init__(self, capacity: int):
        self.map = {}
        self.cap = capacity
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if key in self.map:
            node = self.map[key]
            self.deleteNode(node)
            self.insertAtStart(node)

            return node.val
        return -1


    def put(self, key: int, value: int) -> None:
        if key in self.map:
            node = self.map[key]
            node.val = value
            self.deleteNode(node)
            self.insertAtStart(node)
        else:
            if len(self.map) == self.cap:
                node = self.tail.prev
                self.deleteNode(node)
                del self.map[node.key]
            node = Node(key, value)
            self.map[key] = node
            self.insertAtStart(node)




# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)