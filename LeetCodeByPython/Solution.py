import ListNode
class Solution(object):
    def twoSum(self, nums, target):
        map = {}
        for i in range(len(nums)):
            first = target - nums[i]
            if first in map:
                return map[first],i
            map[nums[i]] = i
        return 0,0

    def addTwoNumbers(self, l1, l2):
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        cf = 0
        result = ListNode(0)
        curr = result
        while l1 != None or l2 != None or cf != 0:
            sum = (0 if l1 == None else l1.val) + (0 if l2 == None else l2.val) + cf
            curr.next=ListNode(sum%10)
            curr=curr.next
            cf=sum/10
            l1=None if l1==None else l1.next
            l2=None if l2==None else l2.next
        return result.next