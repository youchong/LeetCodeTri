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
            curr.next = ListNode(sum % 10)
            curr = curr.next
            cf = sum / 10
            l1 = None if l1 == None else l1.next
            l2 = None if l2 == None else l2.next
        return result.next

    def lengthOfLongestSubstring(self, s):
        if len(s) < 2:
            return len(s)
        i = 0
        j = 1
        maxLength = 1
        map = {}
        map[s[i]] = i

        while j < len(s):
            if s[j] in map:
                if map[s[j]] >= i:
                    length = j - i
                    if length > maxLength:
                        maxLength = length
                    i = map[s[j]] + 1
            map[s[j]] = j
            j = j + 1

        length = j - i
        if length > maxLength:
            maxLength = length

        return maxLength

    def longestPalindrome(self, s):
        if s == None or len(s) < 2:
            return s
        max_left = 0
        max_len = 1
        s_len = len(s)
        start = 0
        while start < s_len - 1 and s_len - start > max_len / 2:
            i = start
            j = start
            while j + 1 < s_len and s[j] == s[j + 1]:
                j+=1
            start = j + 1
            while i > 0 and j + 1 < s_len and s[i - 1] == s[j + 1]:
                j+=1
                i-=1
            if j - i + 1 > max_len:
                max_len = j - i + 1
                max_left = i
        return s[max_left:max_left + max_len]