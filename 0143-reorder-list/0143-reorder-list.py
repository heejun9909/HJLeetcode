# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # def getLen(self, lst: Optional[ListNode]) -> int:
    #     count = 0
    #     while lst:
    #         count += 1
    #         lst = lst.next
    #     return count

    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # get = head
        # listLen = self.getLen(get)
        # cur = head

        # while True:
            
        #     tail = cur
        #     if (listLen-1) > 0:
        #         for i in range(listLen-1):
        #             tail = tail.next
        #     else:
        #         tail.next = None
        #         return

        #     temp = cur.next
        #     cur.next = tail
        #     cur = temp
        #     tail.next = cur

        #     listLen -= 2

        slow, fast = head, head.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        fhalf = head
        shalf = slow.next
        slow.next = None

        cur_shalf = shalf
        prev = None
        while cur_shalf:
            temp = cur_shalf.next
            cur_shalf.next = prev
            prev = cur_shalf
            cur_shalf = temp

        cur_fhalf = fhalf
        while prev:
            temp = cur_fhalf.next
            cur_fhalf.next = prev
            temp1 = prev.next
            cur_fhalf = temp
            prev.next = cur_fhalf
            prev = temp1
            
