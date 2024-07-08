"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # Using Two Passes technique
        oldToCopy = {None: None} # if any key is null, we return null from the hashmap

        # Copy the nodes from the original list and map them into original nodes
        # { original node: copied node(only with the val for now) }
        cur = head
        while cur:
            copy = Node(cur.val)
            oldToCopy[cur] = copy
            cur = cur.next
        
        # In the second pass, we iterate through the hashmap and connect the .next and .random
        # nodes of the copied nodes
        # Since we already have all the copied nodes from the first pass,
        # we can simply connect them using the original nodes' .next and .random keys
        cur = head
        while cur:
            copy = oldToCopy[cur]
            copy.next = oldToCopy[cur.next]
            copy.random = oldToCopy[cur.random]
            cur = cur.next
        
        return oldToCopy[head]