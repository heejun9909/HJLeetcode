# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode()
        dummyCur = dummy

        if k == 1:
            return head
        
        while True:
            cur = head
            for i in range(k - 1):
                cur = cur.next
                if not cur:
                    dummyCur.next = head
                    return dummy.next
            temp = cur.next
            cur.next = None
            dummyCur.next = self.reverseNodes(head)
            head = temp

            for i in range(k):
                dummyCur = dummyCur.next
            
            if not head: break
        
        return dummy.next
        
    def reverseNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        prev = None
        
        while cur:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        return prev