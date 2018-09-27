import heapq

class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = list(set(nums))
        if len(nums) < 3:
            return max(nums)
        h = nums[:3]
        heapq.heapify(h)
        for i in range(3, len(nums)):
            heapq.heappush(h, nums[i])
            heapq.heappop(h)
        return heapq.heappop(h)
