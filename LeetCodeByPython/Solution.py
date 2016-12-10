class Solution(object):
    def twoSum(self, nums, target):
        map={}
        for i in range(len(nums)):
            first=target-nums[i]
            if first in map:
                return map[first],i
            map[nums[i]]=i
        return 0,0