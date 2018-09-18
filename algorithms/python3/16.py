from bisect import bisect_left

class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        rls = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)-2):
            for j in range(i+1, len(nums)-1):
                t = target - nums[i] - nums[j]
                idx = bisect_left(nums, t, j+1)
                if j < idx < len(nums):
                    s = nums[i] + nums[j] + nums[idx]
                    if abs(rls - target) > abs(s - target):
                        rls = s
                if j < idx-1 < len(nums):
                    s = nums[i] + nums[j] + nums[idx-1]
                    if abs(rls - target) > abs(s - target):
                        rls = s
        return rls
