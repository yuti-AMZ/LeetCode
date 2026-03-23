class Solution:
    def reverseKGroup(self, head, k):
        dummy = ListNode(0)
        dummy.next = head
        prev_group = dummy

        while True:
            
            kth = prev_group
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next

            group_start = prev_group.next
            next_group = kth.next

            prev = next_group
            curr = group_start

            while curr != next_group:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp

            prev_group.next = kth
            prev_group = group_start