# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        cur = dummy

        carry = 0
        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            # new digit
            val = v1 + v2 + carry
            carry = val // 10
            val = val % 10
            cur.next = ListNode(val)

            # update ptrs
            cur = cur.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummy.next
        
        # dummy = ListNode((l1.val + l2.val) % 10)
        # carry = (l1.val + l2.val) // 10
        # l1 = l1.next
        # l2 = l2.next

        # cur = dummy
        # while l1 and l2:
        #     cur.next = ListNode((l1.val + l2.val + carry) % 10)
        #     carry = (l1.val + l2.val + carry) // 10
        #     cur = cur.next
        #     l1 = l1.next
        #     l2 = l2.next
        
        # if l1:
        #     while carry:
        #         if l1:
        #             cur.next = ListNode((l1.val + carry) % 10)
        #             carry = (carry + l1.val) // 10
        #             cur = cur.next
        #             l1 = l1.next
        #         else:
        #             cur.next = ListNode(carry)
        #             return dummy
        #     cur.next = l1
                
        # elif l2:
        #     while carry:
        #         if l2:
        #             cur.next = ListNode((l2.val + carry) % 10)
        #             carry = (carry + l2.val) // 10
        #             cur = cur.next
        #             l2 = l2.next
        #         else:
        #             cur.next = ListNode(carry)
        #             return dummy
        #     cur.next = l2

        # elif carry:
        #     cur.next = ListNode(carry)

        # return dummy

        