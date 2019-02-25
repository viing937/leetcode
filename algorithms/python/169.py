class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = nums[0]
        count = 1
        for i in range(1, len(nums)):
            if count == 0:
                ans = nums[i]
            if nums[i] == ans:
                count += 1
            else:
                count -= 1
        return ans
