class Solution:
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l <= 1:
            return l
        state, rls = 0, 1
        for i in range(1, l):
            diff = nums[i] - nums[i-1]
            if state >= 0 and diff < 0:
                state = diff
                rls += 1
            elif state <= 0 and diff > 0:
                state = diff
                rls += 1
        return rls
