class Solution:
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums = nums + nums
        rls = [-1] * len(nums)
        stack = []
        for i in range(len(nums)-1, -1, -1):
            num = nums[i]
            while len(stack) and num >= stack[-1]:
                stack.pop()
            if len(stack):
                rls[i] = stack[-1]
            stack.append(num)
        return rls[:len(nums)//2]
