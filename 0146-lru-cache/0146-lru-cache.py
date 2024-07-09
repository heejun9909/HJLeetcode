class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None
 
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.map = {}   # map { key: node }

        # Set lru to point at the most left node
        # Set mru(most recently used) to point at the most right node
        # Initialize them with dummy nodes and connect them together at first
        # so that we can put nodes in between the lru and mru ptrs
        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left

    # remove from list
    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev

    # insert node at right
    def insert(self, node):
        prev, nxt = self.right.prev, self.right
        prev.next = nxt.prev = node
        node.next, node.prev = nxt, prev

    def get(self, key: int) -> int:
        if key in self.map:
            self.remove(self.map[key])
            self.insert(self.map[key])
            return self.map[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            self.remove(self.map[key])
        self.map[key] = Node(key, value)
        self.insert(self.map[key])

        if len(self.map) > self.capacity:
            # remove from the list and evict the LRU from the hashmap
            lru = self.left.next
            self.remove(lru)
            del self.map[lru.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)