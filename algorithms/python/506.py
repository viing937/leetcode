class Solution:
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        nums = sorted([(nums[i], i) for i in range(len(nums))], reverse=True)
        rls = [0] * len(nums)
        if len(nums) >= 1:
            rls[nums[0][1]] = 'Gold Medal'
        if len(nums) >= 2:
            rls[nums[1][1]] = 'Silver Medal'
        if len(nums) >= 3:
            rls[nums[2][1]] = 'Bronze Medal'
        for i in range(3, len(nums)):
            idx, rank = nums[i][1],  i+1
            rls[idx] = str(rank)
        return rls
