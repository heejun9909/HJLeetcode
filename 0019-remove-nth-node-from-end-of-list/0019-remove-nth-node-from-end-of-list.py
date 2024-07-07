# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        left, right = dummy, head

        for i in range(n):
            right = right.next
        
        while right:
            left = left.next
            right = right.next

        left.next = left.next.next

        return dummy.next
        # if head.next == None:
        #     head = None
        #     return head

        # count, cnthead, prev = 0, head, head

        # while cnthead:
        #     count += 1
        #     cnthead = cnthead.next
            
        # if (count - n - 1) > 0:
        #     for i in range(count - n - 1):
        #         prev = prev.next
        #     cur = prev.next
        #     temp = cur.next
        #     cur.next = None
        #     prev.next = temp
        #     return head
        # elif (count - n - 1) < 0:
        #     temp = head.next
        #     head.next = None
        #     return temp
        # else:
        #     cur = prev.next
        #     temp = cur.next
        #     cur.next = None
        #     prev.next = temp
        #     return head

        
        
        

        