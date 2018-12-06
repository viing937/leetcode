class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        l = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[l-1]:
                nums[l] = nums[i]
                l += 1
        return l
