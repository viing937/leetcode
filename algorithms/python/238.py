class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        rls = [1] * n

        t = 1
        for i in range(1, n):
            t *= nums[i-1]
            rls[i] *= t

        t = 1
        for i in range(n-2, -1, -1):
            t *= nums[i+1]
            rls[i] *= t

        return rls
