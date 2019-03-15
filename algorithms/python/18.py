class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        rls, tmp = [], []
        def nSum(n, start, target):
            if n == 0:
                if target == 0: rls.append(tmp[:])
                return
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i-1]:
                    continue
                if nums[i]*n > target or nums[-1]*n < target:
                    break
                tmp.append(nums[i])
                nSum(n-1, i+1, target-nums[i])
                tmp.pop()
        nSum(4, 0, target)
        return rls
